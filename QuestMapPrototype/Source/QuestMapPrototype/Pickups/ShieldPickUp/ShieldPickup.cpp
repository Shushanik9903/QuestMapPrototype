// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldPickup.h"
#include "QuestMapPrototype/HUD/QuestHUD.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"

void AShieldPickup::BeginPlay()
{
	Super::BeginPlay();
}

void AShieldPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	HandleShieldSpawn();
	
}

void AShieldPickup::HandleShieldSpawn()
{
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (AQuestHUD* QuestHUD = Cast<AQuestHUD>(PC->GetHUD()))
		{
			QuestHUD->ShowVictoryWidget(true);
		}
	}
}
