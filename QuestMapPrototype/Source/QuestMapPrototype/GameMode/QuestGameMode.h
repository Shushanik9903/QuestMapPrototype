// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "QuestGameMode.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShieldSpawn, FVector, SpawnLocation);
UCLASS()
class QUESTMAPPROTOTYPE_API AQuestGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 CoinsCollected = 0; 

	UPROPERTY(EditAnywhere)
	int32 CoinsThreshold = 2;

public:
	
	UPROPERTY(BlueprintAssignable, Category="Events")
    FOnShieldSpawn OnShieldSpawn;

	FORCEINLINE	void SetCoinsCollected(int32 NewCoinsCollected)  { CoinsCollected = NewCoinsCollected;}
	FORCEINLINE int32 GetCoinsCollected() const {return CoinsCollected;}
	FORCEINLINE int32 GetCoinsThreshold() const {return CoinsThreshold;}
};
