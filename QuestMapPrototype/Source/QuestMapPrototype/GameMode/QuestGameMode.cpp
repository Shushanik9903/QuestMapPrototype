// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGameMode.h"
#include "Engine/Engine.h"

AQuestGameMode::AQuestGameMode()
{
    ShieldThreshold = 20;
    CoinMax = 20;
}

void AQuestGameMode::BeginPlay()
{
    Super::BeginPlay();
    if (HasAuthority())
    {
        InitializeDefaultPickups();
    }
}

void AQuestGameMode::RegisterPickup(EPickupType PickupType)
{
    if (!HasAuthority()) return;
    RegisterPickup_Internal(PickupType);
}

void AQuestGameMode::RegisterPickup_Internal(EPickupType PickupType)
{
    FPickupStats& Stats = PickupStats.FindOrAdd(PickupType);

    int32 MaxForType = Stats.Threshold;
    switch (PickupType)
    {
    case EPickupType::Shield:
        MaxForType = ShieldThreshold;
        break;
    case EPickupType::Coin:
        MaxForType = CoinMax;
        break;
    case EPickupType::Health:
        MaxForType = TNumericLimits<int32>::Max();
        break;
    default:
        break;
    }

    if (Stats.Count < MaxForType)
    {
        Stats.Count = FMath::Min(Stats.Count + 1, MaxForType);
    }

    if (PickupType == EPickupType::Shield && Stats.Count >= ShieldThreshold)
    {
        if (OnShieldSpawn.IsBound())
        {
            OnShieldSpawn.Broadcast(FVector::ZeroVector);
        }
    }

    OnPickupStatsUpdated.Broadcast(PickupType, Stats);
    Multicast_PickupStatsUpdated(PickupType, Stats);

    if (GEngine)
    {
        const FString PickupName = UEnum::GetValueAsName(PickupType).ToString();
        const FString Msg = FString::Printf(TEXT("%s: %d / %d"), *PickupName, Stats.Count, MaxForType);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Msg);
    }
}

void AQuestGameMode::AddMapQuestGoal(EPickupType Type, const FPickupStats& Goal)
{
    if (!HasAuthority()) return;

    FPickupStats& Stats = PickupStats.FindOrAdd(Type);
    Stats.Threshold = Goal.Threshold;
    Stats.bIsDynamic = Goal.bIsDynamic;
    Stats.Count = FMath::Min(Stats.Count, Stats.Threshold);

    OnPickupStatsUpdated.Broadcast(Type, Stats);
    Multicast_PickupStatsUpdated(Type, Stats);
}

void AQuestGameMode::SetCoinsCollected(int32 NewCoinsCollected)
{
    if (!HasAuthority())
    {
        CoinsCollected = NewCoinsCollected;
        return;
    }

    CoinsCollected = NewCoinsCollected;

    FPickupStats& Stats = PickupStats.FindOrAdd(EPickupType::Coin);
    Stats.Count = FMath::Clamp(CoinsCollected, 0, CoinMax);
    Stats.Threshold = FMath::Max(Stats.Threshold, CoinMax);

    OnPickupStatsUpdated.Broadcast(EPickupType::Coin, Stats);
    Multicast_PickupStatsUpdated(EPickupType::Coin, Stats);
}

void AQuestGameMode::InitializeDefaultPickups()
{
    {
        FPickupStats& CoinStats = PickupStats.FindOrAdd(EPickupType::Coin);
        CoinStats.Threshold = CoinMax;
        CoinStats.Count = FMath::Clamp(CoinStats.Count, 0, CoinStats.Threshold);
        CoinStats.bIsDynamic = true;
        OnPickupStatsUpdated.Broadcast(EPickupType::Coin, CoinStats);
        Multicast_PickupStatsUpdated(EPickupType::Coin, CoinStats);
    }
    {
        FPickupStats& ShieldStats = PickupStats.FindOrAdd(EPickupType::Shield);
        ShieldStats.Threshold = 1;
        ShieldStats.Count = FMath::Clamp(ShieldStats.Count, 0, ShieldStats.Threshold);
        ShieldStats.bIsDynamic = false;
        OnPickupStatsUpdated.Broadcast(EPickupType::Shield, ShieldStats);
        Multicast_PickupStatsUpdated(EPickupType::Shield, ShieldStats);
    }
}

void AQuestGameMode::Multicast_PickupStatsUpdated_Implementation(EPickupType PickupType, const FPickupStats& Stats)
{
    OnPickupStatsUpdated.Broadcast(PickupType, Stats);
}
