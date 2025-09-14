// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "QuestGameMode.generated.h"

UENUM(BlueprintType)
enum class EPickupType : uint8
{
    None UMETA(DisplayName="None"),
    Coin UMETA(DisplayName="Coin"),
    Shield UMETA(DisplayName="Shield"),
    Health UMETA(DisplayName="Health"),
    Star UMETA(DisplayName="Star")
};

USTRUCT(BlueprintType)
struct FPickupStats
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int32 Count = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int32 Threshold = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool bIsDynamic = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickupStatsUpdated, EPickupType, PickupType, const FPickupStats&, Stats);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShieldSpawn, FVector, SpawnLocation);

UCLASS()
class QUESTMAPPROTOTYPE_API AQuestGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    AQuestGameMode();

    virtual void BeginPlay() override;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickups")
    int32 ShieldThreshold = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickups")
    int32 CoinMax = 20;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnPickupStatsUpdated OnPickupStatsUpdated;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnShieldSpawn OnShieldSpawn;

    UFUNCTION(BlueprintCallable, Category = "Pickups")
    void RegisterPickup(EPickupType PickupType);

    UFUNCTION(BlueprintCallable, Category = "Pickups")
    void AddMapQuestGoal(EPickupType Type, const FPickupStats& Goal);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickups")
    TMap<EPickupType, FPickupStats> PickupStats;

    UPROPERTY()
    int32 CoinsCollected = 0;

    UPROPERTY(EditAnywhere)
    int32 CoinsThreshold = 20;

    UFUNCTION(BlueprintCallable, Category = "Pickups")
    void SetCoinsCollected(int32 NewCoinsCollected);

    FORCEINLINE int32 GetCoinsCollected() const { return CoinsCollected; }
    FORCEINLINE int32 GetCoinsThreshold() const { return CoinsThreshold; }

protected:
    void InitializeDefaultPickups();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PickupStatsUpdated(EPickupType PickupType, const FPickupStats& Stats);

    void Multicast_PickupStatsUpdated_Implementation(EPickupType PickupType, const FPickupStats& Stats);

private:
    void RegisterPickup_Internal(EPickupType PickupType);
};