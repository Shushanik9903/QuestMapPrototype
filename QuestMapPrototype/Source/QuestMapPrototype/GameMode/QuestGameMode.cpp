// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGameMode.h"

void AQuestGameMode::RegisterPickup(EPickupType PickupType)
{
    FPickupStats& Stats = PickupStats.FindOrAdd(PickupType);
    Stats.Count++;

    for (auto& Elem : PickupStats)
    {
        FString PickupName;
        switch (Elem.Key)
        {
        case EPickupType::Coin:   PickupName = TEXT("Coin"); break;
        case EPickupType::Shield: PickupName = TEXT("Shield"); break;
        case EPickupType::Health: PickupName = TEXT("Health"); break;
        default: PickupName = TEXT("None"); break;
        }

        FString Msg = FString::Printf(TEXT("%s count: %d"), *PickupName, Elem.Value.Count);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Msg);
        }
    }
}
