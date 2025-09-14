// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "QuestGameMode.generated.h"

/**
 * 
 */
 
 UENUM(BlueprintType)
enum class EPickupType : uint8
{
    None,
    Coin,
    Shield,
    Health
};

USTRUCT(BlueprintType)
struct FPickupStats
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int32 Count = 0;
};

USTRUCT(BlueprintType)
struct FMapQuestGoal
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPickupType PickupType = EPickupType::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CollectedCount = 0;

	bool bIsDynamic = false;

	bool operator ==(const FMapQuestGoal& NewGoal) const
	{
		const bool bPickupType = PickupType == NewGoal.PickupType;
		const bool bMaxCount = MaxCount == NewGoal.MaxCount;
		return bPickupType && bMaxCount;
	}
};

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

	UFUNCTION(BlueprintCallable, Category="Pickups")
	void RegisterPickup(EPickupType PickupType);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pickups")
    TMap<EPickupType, FPickupStats> PickupStats;
};
