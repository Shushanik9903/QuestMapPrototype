// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "CoinPickup.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API ACoinPickup : public APickup
{
	GENERATED_BODY()

public:
	ACoinPickup();

protected:
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	) override;

public:

	UFUNCTION()
	void MoveToLocation(const FVector& NewLocation);

protected:
	virtual void BeginPlay() override;

};
