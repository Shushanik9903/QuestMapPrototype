// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestMapPrototype/Pickups/CoinPickUp/CoinPickup.h"
#include "QuestMapPrototype/Pickups/EnergyPickUp/HealthPickup.h"
#include "SpawnManager.generated.h"


USTRUCT()
struct FSpawnPointBase
{
    GENERATED_BODY()
    FVector Location = FVector::ZeroVector;
    AActor* SourceActor = nullptr;
};

USTRUCT()
struct FSpawnCoinsPoint : public FSpawnPointBase
{
    GENERATED_BODY()
};

USTRUCT()
struct FSpawnEnergyPoint : public FSpawnPointBase
{
    GENERATED_BODY()
    AStaticMeshActor* SourceMesh = nullptr;
};

UCLASS()
class QUESTMAPPROTOTYPE_API ASpawnManager : public AActor
{
    GENERATED_BODY()
public:
    ASpawnManager();

protected:
    virtual void BeginPlay() override;
    void GatherGenericPoints(const FString& NameSubstring, TArray<FSpawnPointBase>& OutPoints, TFunction<void(const AActor*, FSpawnPointBase&)> SetSource);
    void GatherHousesAndSpawnCoins();
    void GatherBarrelsAndSpawnEnergy();
    FVector FindNearCenterLocation(const AActor* LActor) const;
    bool GetLandscapeHitBelow(const FVector& Start, FVector& OutHitLocation, AActor*& OutHitActor) const;
    void SpawnCoins();
    void SpawnStaticCoins();
    void SpawnEnergy();
    void OnRelocateTick();
    FVector ChooseValidSpawnLocationFromArray(const TArray<FSpawnPointBase>& Points, const TArray<AActor*>& ExistingActors) const;

    UPROPERTY()
    TArray<FSpawnCoinsPoint> SpawnPointsForCoins;

    UPROPERTY()
    TArray<FSpawnEnergyPoint> SpawnPointsForEnergy;

    UPROPERTY()
	TArray<class ACoinPickup*> SpawnedCoins; 

    UPROPERTY()
	TArray<class AStaticCoinPickup*> SpawnedStaticCoins;

    UPROPERTY()
    TArray<class AHealthPickup*> SpawnedEnergy;

    FTimerHandle RelocateTimerHandle;
    
    UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<ACoinPickup> CoinClass; 

    UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AStaticCoinPickup> StaticCoinClass;

    UPROPERTY(EditAnywhere, Category="Spawn")
    TSubclassOf<AHealthPickup> EnergyClass;

    UPROPERTY(EditAnywhere, Category="Spawn")
    float RelocateInterval = 6.0f;

    UPROPERTY(EditAnywhere, Category="Spawn")
    float MinSeparation = 50.f;

    UPROPERTY(EditAnywhere, Category="Spawn|Landscape")
    float TraceDownDistance = 2000.f;

    UPROPERTY(EditAnywhere, Category="Spawn|Landscape")
    float SpawnHeightAboveSurface = 50.f;
};