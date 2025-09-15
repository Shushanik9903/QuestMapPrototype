// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGameMode.h"
#include "Engine/Engine.h"

AQuestGameMode::AQuestGameMode()
{
    ShieldThreshold = 1;
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
    if (PickupType == EPickupType::Health || PickupType == EPickupType::None) return;
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
    OnPickupStatsUpdated.Broadcast(PickupType, Stats);
    Multicast_PickupStatsUpdated(PickupType, Stats);
	/*if (GEngine)
	{
		const FString PickupName = UEnum::GetValueAsName(PickupType).ToString();
		const FString Msg = FString::Printf(TEXT("%s: %d / %d"), *PickupName, Stats.Count, MaxForType);
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Msg);
	}*/
    bool bAllReached = true;
    bool bHasRelevantEntries = false;
    for (const TPair<EPickupType, FPickupStats>& Pair : PickupStats)
    {
        const EPickupType Key = Pair.Key;
        const FPickupStats& PS = Pair.Value;
        if (PS.Threshold <= 0)
        {
            continue;
        }
        bHasRelevantEntries = true;
        int32 Required = PS.Threshold;
        if (Key == EPickupType::Shield)
        {
            Required = FMath::Max(1, ShieldThreshold);
        }
        else if (Key == EPickupType::Coin)
        {
            Required = FMath::Max(0, CoinMax);
        }
        if (PS.Count < Required)
        {
            bAllReached = false;
            break;
        }
    }
    if (bHasRelevantEntries && bAllReached)
    {
        const FPickupStats* ShieldStatsPtr = PickupStats.Find(EPickupType::Shield);
        const bool bShieldReady = (ShieldStatsPtr && ShieldStatsPtr->Count >= FMath::Max(1, ShieldThreshold));
        if (bShieldReady)
        {
            if (OnShieldSpawn.IsBound())
            {
                OnShieldSpawn.Broadcast(FVector::ZeroVector);
            }
        }
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

void AQuestGameMode::SetCoinsCollected(EPickupType PickupType)
{
    if (!HasAuthority())
    {
        return;
    }
    FPickupStats& Stats = PickupStats.FindOrAdd(PickupType);
    Stats.Count = FMath::Clamp(Stats.Count + 1, 0, CoinMax);
  //  Stats.Threshold = FMath::Max(Stats.Threshold, CoinMax);
    OnPickupStatsUpdated.Broadcast(PickupType, Stats);
    Multicast_PickupStatsUpdated(PickupType, Stats);
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
