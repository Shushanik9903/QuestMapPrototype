// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMapPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "QuestMapPrototype/Pickups/Pickup.h"

void AQuestMapPlayerController::ShowAllPickupIcons(bool bShow)
{
    TArray<AActor*> FoundCoins;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APickup::StaticClass(), FoundCoins);

    for (AActor* Actor : FoundCoins)
    {
        if (APickup* PickupActor = Cast<APickup>(Actor))
        {
            PickupActor->ShowIcon(bShow);
        }
    }
}