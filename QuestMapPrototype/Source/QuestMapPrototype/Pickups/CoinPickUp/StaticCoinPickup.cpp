// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticCoinPickup.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"

AStaticCoinPickup::AStaticCoinPickup()
{
    PrimaryActorTick.bCanEverTick = false;

    PickupType = EPickupType::Star;
}

void AStaticCoinPickup::BeginPlay()
{
    Super::BeginPlay();
}

void AStaticCoinPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    if (AQuestGameMode* GM = Cast<AQuestGameMode>(GetWorld()->GetAuthGameMode()))
    {
       if (GM->PickupStats.Find(PickupType) == nullptr) return;
       GM->RegisterPickup(PickupType); 
    }
}
void AStaticCoinPickup::MoveToLocation(const FVector& NewLocation)
{
	SetActorLocation(NewLocation);
}

