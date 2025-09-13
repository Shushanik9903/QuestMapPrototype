// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestHUD.h"

#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"
#include "QuestMapPrototype/UI/FullMap/FullMapUserWidget.h"
#include "QuestMapPrototype/UI/Journal/JournalUserWidget.h"


void AQuestHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AQuestHUD::ShowMapWidget()
{
	AQuestMapPlayerController* PC = Cast<AQuestMapPlayerController>(GetOwningPlayerController()); 
	if (!IsValid(PC))
	{
		return;
	}
	if(!IsValid(FullMapWidgetRef))
	{
		if(IsValid(FullMapSubClass))
		{
			FullMapWidgetRef = CreateWidget<UFullMapUserWidget>(PC, FullMapSubClass);
		}
	}
	if (IsValid(FullMapWidgetRef))
	{
		if(!FullMapWidgetRef->IsInViewport())
		{
			FullMapWidgetRef->AddToViewport(1000);
		}
		else
		{
			FullMapWidgetRef->RemoveFromParent();
		}
	}
}

void AQuestHUD::ShowJournalWidget()
{
	AQuestMapPlayerController* PC = Cast<AQuestMapPlayerController>(GetOwningPlayerController()); 
	if (!IsValid(PC))
	{
		return;
	}
	if(!IsValid(JournalWidgetRef))
	{
		if(IsValid(JournalSubClass))
		{
			JournalWidgetRef = CreateWidget<UJournalUserWidget>(PC, JournalSubClass);
		}
	}
	if (IsValid(JournalWidgetRef))
	{
		if(!JournalWidgetRef->IsInViewport())
		{
			JournalWidgetRef->AddToViewport(1000);
		}
		else
		{
			JournalWidgetRef->RemoveFromParent();
		}
	}
}
