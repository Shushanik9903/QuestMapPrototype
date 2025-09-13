// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGameMode.h"

void AQuestGameMode::RegisterPickup(EPickupType PickupType)
{
    FPickupStats& Stats = PickupStats.FindOrAdd(PickupType);
    Stats.Count++;
}
