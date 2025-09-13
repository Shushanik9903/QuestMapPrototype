// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "QuestMapPrototype/HUD/QuestHUD.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/CoinPickup.h"
#include "QuestMapPrototype/Pickups/ShieldPickUp/ShieldPickup.h"

// Sets default values
AShieldSpawner::AShieldSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

}

void AShieldSpawner::BeginPlay()
{
	Super::BeginPlay();

    if (HasAuthority())
    {
        if (AQuestGameMode* GM = Cast<AQuestGameMode>(GetWorld()->GetAuthGameMode()))
        {
            GM->OnShieldSpawn.AddDynamic(this, &AShieldSpawner::SpawnShield);
        }
    }
}

void AShieldSpawner::SpawnShield(FVector /*IgnoredLocation*/)
{
    if (!ShieldClass) return;

    FActorSpawnParameters SpawnParams;
    FVector SpawnLocation = GetActorLocation();

    TArray<AActor*> FoundCoins;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACoinPickup::StaticClass(), FoundCoins);

    for (AActor* Coin : FoundCoins)
    {
        if (Coin)
        {
            Coin->Destroy();
        }
    }

    GetWorld()->SpawnActor<AShieldPickup>(ShieldClass, SpawnLocation + FVector(100.f, 0, 0), FRotator::ZeroRotator, SpawnParams);
}


void AShieldSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

