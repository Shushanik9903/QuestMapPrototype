// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "ShieldPickup.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API AShieldPickup : public APickup
{
	GENERATED_BODY()
public:

	AShieldPickup() { PickupType = EPickupType::Shield; }
protected:
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	) override;

	virtual void BeginPlay() override;
private:

	UPROPERTY(EditAnywhere)
	float ShieldReplenishAmount = 100.f;

	UPROPERTY(EditAnywhere)
	float ShieldReplenishTime = 5.f;

public:
	UFUNCTION()
	void HandleShieldSpawn();
};
