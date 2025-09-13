// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickup.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "QuestMapPrototype/Pickups/ShieldPickUp/ShieldPickup.h"

void ACoinPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    
        if (AQuestGameMode* GM = Cast<AQuestGameMode>(GetWorld()->GetAuthGameMode()))
        {
            int32 NewCoinsCollected = GM->GetCoinsCollected() + 1;
            int32 CoinsNeededForShield = GM->GetCoinsThreshold();

            GM->SetCoinsCollected(NewCoinsCollected);

            if (NewCoinsCollected >= CoinsNeededForShield)
            {
                GM->OnShieldSpawn.Broadcast(GetActorLocation());
            }
        }

	Destroy();
}

ACoinPickup::ACoinPickup()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACoinPickup::MoveToLocation(const FVector& NewLocation)
{
	SetActorLocation(NewLocation);
}

void ACoinPickup::BeginPlay()
{
	Super::BeginPlay();
}
