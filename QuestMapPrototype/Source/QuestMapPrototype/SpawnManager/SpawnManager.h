// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/CoinPickup.h"
#include "SpawnManager.generated.h"

USTRUCT()
struct FSpawnPoint
{
	GENERATED_BODY()
	FVector Location;
	AActor* SourceWall = nullptr;
};
UCLASS()
class QUESTMAPPROTOTYPE_API ASpawnManager : public AActor
{
	GENERATED_BODY()
public:
	ASpawnManager();

	bool GetLandscapeHitBelow(const FVector& Start, FVector& OutHitLocation) const;

protected:
	virtual void BeginPlay() override;

	void GatherWallsAndSpawnPoints();
	void SpawnCoins();
	FVector FindNearCenterLocation(const AActor* HouseActor) const;
	void OnRelocateTick();

	UPROPERTY()
	TArray<FSpawnPoint> SpawnPoints;

	UPROPERTY()
	TArray<ACoinPickup*> SpawnedCoins;

	FTimerHandle RelocateTimerHandle;
	
	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<ACoinPickup> CoinClass;

	UPROPERTY(EditAnywhere, Category="Spawn")
	float RelocateInterval = 6.0f;

	UPROPERTY(EditAnywhere, Category="Spawn")
	float MinSeparation = 50.f;

	UPROPERTY(EditAnywhere, Category="Spawn|Landscape")
	float TraceDownDistance = 2000.f;

	UPROPERTY(EditAnywhere, Category="Spawn|Landscape")
	float SpawnHeightAboveSurface = 20.f;
};
