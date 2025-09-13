// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShieldSpawner.generated.h"

UCLASS()
class QUESTMAPPROTOTYPE_API AShieldSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AShieldSpawner();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Shield")
    TSubclassOf<class AShieldPickup> ShieldClass;

	UFUNCTION()
    void SpawnShield(FVector SpawnLocation);
};
