// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "EngineUtils.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Landscape.h"
#include "QuestMapPrototype/GameInstance/QuestGameInstance.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/CoinPickup.h"


ASpawnManager::ASpawnManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASpawnManager::BeginPlay()
{
    Super::BeginPlay();
    GatherWallsAndSpawnPoints();
    SpawnCoins();
    if (RelocateInterval > 0.f)
    {
        GetWorldTimerManager().SetTimer(RelocateTimerHandle, this, &ASpawnManager::OnRelocateTick, RelocateInterval, true);
    }
}

void ASpawnManager::GatherWallsAndSpawnPoints()
{
    SpawnPoints.Empty();
    for (TActorIterator<AActor> It(GetWorld()); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor) continue;

        FString Name = Actor->GetName();
        if (Name.ToLower().Contains(TEXT("house")))
        {
            FVector Near = FindNearCenterLocation(Actor);
            FVector TraceStart = Near + FVector(0.f, 0.f, TraceDownDistance * 0.5f);
            FVector HitLocation;
            if (GetLandscapeHitBelow(TraceStart, HitLocation))
            {
                FVector SpawnLoc = HitLocation + FVector(0.f, 0.f, SpawnHeightAboveSurface);
                FSpawnPoint SP;
                SP.Location = SpawnLoc;
                SP.SourceWall = Actor;
                SpawnPoints.Add(SP);
            }
            else
            {
                FVector FallbackStart = Near + FVector(0.f, 0.f, 300.f);
                if (GetLandscapeHitBelow(FallbackStart, HitLocation))
                {
                    FVector SpawnLoc = HitLocation + FVector(0.f, 0.f, SpawnHeightAboveSurface);
                    FSpawnPoint SP;
                    SP.Location = SpawnLoc;
                    SP.SourceWall = Actor;
                    SpawnPoints.Add(SP);
                }
                else
                {
                    FVector SpawnLoc = Near + FVector(0.f, 0.f, SpawnHeightAboveSurface);
                    FSpawnPoint SP;
                    SP.Location = SpawnLoc;
                    SP.SourceWall = Actor;
                    SpawnPoints.Add(SP);
                }
            }
        }
    }
}

FVector ASpawnManager::FindNearCenterLocation(const AActor* HouseActor) const
{
    if (!HouseActor) return FVector::ZeroVector;
    FVector Origin;
    FVector BoxExtent;
    HouseActor->GetActorBounds(true, Origin, BoxExtent);
    FVector WorldCenter = FVector::ZeroVector;
    FVector Dir = (WorldCenter - Origin);
    if (Dir.IsNearlyZero()) return Origin;
    Dir.Normalize();
    float MaxExtent = BoxExtent.Size();
    FVector Candidate = Origin + Dir * MaxExtent * 0.6f;
    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(HouseActor);
    bool bHit = GetWorld()->SweepSingleByChannel(Hit, Candidate + FVector(0,0,50.f), Candidate - FVector(0,0,50.f),
        FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(20.f), Params);
    if (!bHit) return Candidate;
    return Origin;
}

bool ASpawnManager::GetLandscapeHitBelow(const FVector& Start, FVector& OutHitLocation) const
{
    FVector End = Start - FVector(0.f, 0.f, TraceDownDistance);

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.bTraceComplex = true;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_WorldStatic, Params);
    if (!bHit) return false;

    if (Hit.GetActor())
    {
        if (Hit.GetActor()->IsA(ALandscape::StaticClass()))
        {
            OutHitLocation = Hit.ImpactPoint;
            return true;
        }

        if (Hit.Component.IsValid())
        {
            if (Hit.Component->IsA(ULandscapeComponent::StaticClass()))
            {
                OutHitLocation = Hit.ImpactPoint;
                return true;
            }
        }
    }
    return false;
}

void ASpawnManager::SpawnCoins()
{
    SpawnedCoins.Empty();
    UQuestGameInstance* GI = Cast<UQuestGameInstance>(GetGameInstance());
    if (!GI) return;
    int32 CoinCount = GI->CoinCount;
    if (CoinCount <= 0 || SpawnPoints.Num() == 0 || !CoinClass) return;
    for (int32 i = 0; i < CoinCount; ++i)
    {
        int32 PickIdx = FMath::RandRange(0, SpawnPoints.Num() - 1);
        FVector Loc = SpawnPoints[PickIdx].Location;
        int tries = 0;
        while (tries < 10)
        {
            bool bOk = true;
            for (ACoinPickup* C : SpawnedCoins)
            {
                if (!C) continue;
                if (FVector::DistSquared(C->GetActorLocation(), Loc) < MinSeparation * MinSeparation)
                {
                    bOk = false;
                    break;
                }
            }
            if (bOk) break;
            PickIdx = FMath::RandRange(0, SpawnPoints.Num() - 1);
            Loc = SpawnPoints[PickIdx].Location;
            ++tries;
        }
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        Loc.Z = 890;
        ACoinPickup* NewCoin = GetWorld()->SpawnActor<ACoinPickup>(CoinClass, Loc, FRotator::ZeroRotator, Params);
        if (NewCoin)
        {
            SpawnedCoins.Add(NewCoin);
        }
    }
}

void ASpawnManager::OnRelocateTick()
{
    if (SpawnedCoins.Num() == 0 || SpawnPoints.Num() == 0) return;

    for (ACoinPickup* Coin : SpawnedCoins)
    {
        if (!Coin) continue;

        FVector Current = Coin->GetActorLocation();

        int tries = 0;
        FVector Chosen = Current;
        while (tries < 20)
        {
            int pick = FMath::RandRange(0, SpawnPoints.Num() - 1);
            FVector Candidate = SpawnPoints[pick].Location;

            if (FVector::DistSquared(Candidate, Current) < KINDA_SMALL_NUMBER)
            {
                ++tries;
                continue;
            }
            bool bOk = true;
            for (ACoinPickup* Other : SpawnedCoins)
            {
                if (!Other || Other == Coin) continue;
                if (FVector::DistSquared(Other->GetActorLocation(), Candidate) < MinSeparation * MinSeparation)
                {
                    bOk = false;
                    break;
                }
            }
            if (bOk)
            {
                Chosen = Candidate;
                break;
            }
            ++tries;
        }
        Coin->MoveToLocation(Chosen);
    }
}