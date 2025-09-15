// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../StarPickUp.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "StaticCoinPickup.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API AStaticCoinPickup : public AStarPickUp
{
	GENERATED_BODY()


public:
	AStaticCoinPickup();
protected:
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	EPickupType PickupType = EPickupType::None;
	
	virtual void BeginPlay() override;
public:
	
	UFUNCTION()
	void MoveToLocation(const FVector& NewLocation);

};
