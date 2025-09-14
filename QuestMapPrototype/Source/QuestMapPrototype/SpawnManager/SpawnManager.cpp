// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "EngineUtils.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Engine/StaticMeshActor.h"
#include "QuestMapPrototype/GameInstance/QuestGameInstance.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/CoinPickup.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/StaticCoinPickup.h"


DEFINE_LOG_CATEGORY_STATIC(LogSpawnManager, Log, All);

ASpawnManager::ASpawnManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASpawnManager::BeginPlay()
{
    Super::BeginPlay();
    GatherHousesAndSpawnCoins();
    GatherBarrelsAndSpawnEnergy();
    SpawnCoins();
    SpawnStaticCoins();
    SpawnEnergy();
    if (RelocateInterval > 0.f)
    {
        GetWorldTimerManager().SetTimer(RelocateTimerHandle, this, &ASpawnManager::OnRelocateTick, RelocateInterval, true);
    }
}

void ASpawnManager::GatherGenericPoints(const FString& NameSubstring, TArray<FSpawnPointBase>& OutPoints, TFunction<void(const AActor*, FSpawnPointBase&)> SetSource)
{
    OutPoints.Empty();

    FVector WorldCenter = FVector::ZeroVector;
    for (TActorIterator<AActor> It(GetWorld()); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor) continue;
        FString Name = Actor->GetName();
        if (!Name.ToLower().Contains(NameSubstring.ToLower())) continue;
        FVector Origin;
        FVector BoxExtent;
        Actor->GetActorBounds(true, Origin, BoxExtent);
        FVector Dir = (WorldCenter - Origin);
        if (Dir.IsNearlyZero()) Dir = FVector::ForwardVector;
        Dir.Normalize();
        float MaxExtent = BoxExtent.Size();
        FVector Candidate = Origin + Dir * MaxExtent * 0.6f;
        FVector TraceStart = Candidate + FVector(0.f, 0.f, TraceDownDistance * 0.5f);
        AActor* HitActor = nullptr;
        FVector HitLocation;
        if (GetLandscapeHitBelow(TraceStart, HitLocation, HitActor))
        {
            FVector SpawnLoc = HitLocation + FVector(0.f, 0.f, SpawnHeightAboveSurface);
            FSpawnPointBase P;
            P.Location = SpawnLoc;
            P.SourceActor = Actor;
            SetSource(Actor, P);
            OutPoints.Add(P);
        }
        else
        {
            FVector SpawnLoc = Candidate + FVector(0.f, 0.f, SpawnHeightAboveSurface);
            FSpawnPointBase P;
            P.Location = SpawnLoc;
            P.SourceActor = Actor;
            SetSource(Actor, P);
            OutPoints.Add(P);
        }
    }
}

void ASpawnManager::GatherHousesAndSpawnCoins()
{
    GatherGenericPoints(TEXT("house"),
        reinterpret_cast<TArray<FSpawnPointBase>&>(SpawnPointsForCoins),
        [](const AActor* Actor, FSpawnPointBase& OutP)
        {
        }
    );
}

void ASpawnManager::GatherBarrelsAndSpawnEnergy()
{
    TArray<FSpawnPointBase> TempPoints;
    GatherGenericPoints(TEXT("prop_barrel"), TempPoints,
        [](const AActor* Actor, FSpawnPointBase& OutP)
        {
        }
    );
    SpawnPointsForEnergy.Empty();
    for (const FSpawnPointBase& P : TempPoints)
    {
        FSpawnEnergyPoint E;
        E.Location = P.Location;
        E.SourceMesh = Cast<AStaticMeshActor>(P.SourceActor);
        E.SourceActor = P.SourceActor;
        SpawnPointsForEnergy.Add(E);
    }
}

FVector ASpawnManager::FindNearCenterLocation(const AActor* LActor) const
{
    if (!LActor) return FVector::ZeroVector;
    FVector Origin;
    FVector BoxExtent;
    LActor->GetActorBounds(true, Origin, BoxExtent);
    FVector WorldCenter = FVector::ZeroVector;
    FVector Dir = (WorldCenter - Origin);
    if (Dir.IsNearlyZero()) return Origin;
    Dir.Normalize();
    float MaxExtent = BoxExtent.Size();
    FVector Candidate = Origin + Dir * MaxExtent * 0.6f;
    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(const_cast<AActor*>(LActor));
    bool bHit = GetWorld()->SweepSingleByChannel(Hit, Candidate + FVector(0,0,50.f), Candidate - FVector(0,0,50.f),
        FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(20.f), Params);
    if (!bHit) return Candidate;
    return Origin;
}

bool ASpawnManager::GetLandscapeHitBelow(const FVector& Start, FVector& OutHitLocation, AActor*& OutHitActor) const
{
    OutHitActor = nullptr;
    FVector End = Start - FVector(0.f, 0.f, TraceDownDistance);
    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.bTraceComplex = true;
    Params.AddIgnoredActor(this);
    bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_WorldStatic, Params);
    if (!bHit) return false;
    OutHitLocation = Hit.ImpactPoint;
    OutHitActor = Hit.GetActor();
    return true;
}

FVector ASpawnManager::ChooseValidSpawnLocationFromArray(const TArray<FSpawnPointBase>& Points, const TArray<AActor*>& ExistingActors) const
{
    if (Points.Num() == 0) return FVector::ZeroVector;

    for (int attempt = 0; attempt < 20; ++attempt)
    {
        int32 idx = FMath::RandRange(0, Points.Num() - 1);
        FVector Candidate = Points[idx].Location;
        bool bOk = true;
        for (AActor* Existing : ExistingActors)
        {
            if (!Existing) continue;
            if (FVector::DistSquared(Existing->GetActorLocation(), Candidate) < MinSeparation * MinSeparation)
            {
                bOk = false;
                break;
            }
        }
        if (bOk) return Candidate;
    }
    return Points[0].Location;
}

void ASpawnManager::SpawnCoins()
{
    SpawnedCoins.Empty();
    UQuestGameInstance* GI = Cast<UQuestGameInstance>(GetGameInstance());
    if (!GI) return;
    int32 CoinCount = GI->CoinCount;
    if (CoinCount <= 0 || SpawnPointsForCoins.Num() == 0 || !CoinClass) return;

    for (int32 i = 0; i < CoinCount; ++i)
    {
        FVector Loc = ChooseValidSpawnLocationFromArray(reinterpret_cast<const TArray<FSpawnPointBase>&>(SpawnPointsForCoins),
            reinterpret_cast<const TArray<AActor*>&>(SpawnedCoins)); 

        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        ACoinPickup* NewCoin = GetWorld()->SpawnActor<ACoinPickup>(CoinClass, Loc, FRotator::ZeroRotator, Params);
        if (NewCoin)
        {
            SpawnedCoins.Add(NewCoin);
        }
    }
}

void ASpawnManager::SpawnStaticCoins()
{
    SpawnedStaticCoins.Empty();
    UQuestGameInstance* GI = Cast<UQuestGameInstance>(GetGameInstance());
    if (!GI) return;
    int32 CoinCount = GI->CoinCount;
    if (CoinCount <= 0 || SpawnPointsForCoins.Num() == 0 || !CoinClass) return;

    for (int32 i = 0; i < CoinCount; ++i)
    {
        FVector Loc = ChooseValidSpawnLocationFromArray(reinterpret_cast<const TArray<FSpawnPointBase>&>(SpawnPointsForCoins),
            reinterpret_cast<const TArray<AActor*>&>(SpawnedStaticCoins));

        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        AStaticCoinPickup* NewCoin = GetWorld()->SpawnActor<AStaticCoinPickup>(StaticCoinClass, Loc, FRotator::ZeroRotator, Params);
        if (NewCoin)
        {
            SpawnedStaticCoins.Add(NewCoin);
        }
    }
}

void ASpawnManager::SpawnEnergy()
{
    SpawnedEnergy.Empty();
    UQuestGameInstance* GI = Cast<UQuestGameInstance>(GetGameInstance());
    if (!GI) return;
    int32 EnergyCount = GI->EnergyCount;
    if (EnergyCount <= 0 || SpawnPointsForEnergy.Num() == 0 || !EnergyClass) return;

    for (int32 i = 0; i < EnergyCount; ++i)
    {
        TArray<FSpawnPointBase> BasePoints;
        BasePoints.Reserve(SpawnPointsForEnergy.Num());
        for (const FSpawnEnergyPoint& E : SpawnPointsForEnergy)
        {
            FSpawnPointBase B;
            B.Location = E.Location;
            B.SourceActor = E.SourceMesh;
            BasePoints.Add(B);
        }
        FVector Loc = ChooseValidSpawnLocationFromArray(BasePoints, reinterpret_cast<const TArray<AActor*>&>(SpawnedEnergy));
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        AHealthPickup* NewEnergy = GetWorld()->SpawnActor<AHealthPickup>(EnergyClass, Loc, FRotator::ZeroRotator, Params);
        if (NewEnergy)
        {
            SpawnedEnergy.Add(NewEnergy);
        }
    }
}

void ASpawnManager::OnRelocateTick()
{
    if (SpawnedCoins.Num() > 0 && SpawnPointsForCoins.Num() > 0)
    {
        for (ACoinPickup* Coin : SpawnedCoins)
        {
            if (!Coin) continue;
            FVector Chosen = ChooseValidSpawnLocationFromArray(reinterpret_cast<const TArray<FSpawnPointBase>&>(SpawnPointsForCoins),
                reinterpret_cast<const TArray<AActor*>&>(SpawnedCoins));
            Coin->MoveToLocation(Chosen);
        }
    }
    if (SpawnedEnergy.Num() > 0 && SpawnPointsForEnergy.Num() > 0)
    {
        for (AHealthPickup* Energy : SpawnedEnergy)
        {
            if (!Energy) continue;
            TArray<AActor*> ExistingEnergyActors;
            ExistingEnergyActors.Reserve(SpawnedEnergy.Num());
            for (AHealthPickup* E : SpawnedEnergy) ExistingEnergyActors.Add(E);
            FVector Chosen = ChooseValidSpawnLocationFromArray(reinterpret_cast<const TArray<FSpawnPointBase>&>(SpawnPointsForEnergy), ExistingEnergyActors);
            Energy->MoveToLocation(Chosen);
        }
    }
}