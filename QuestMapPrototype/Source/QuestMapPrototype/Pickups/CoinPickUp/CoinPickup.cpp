// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickup.h"

void ACoinPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
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
