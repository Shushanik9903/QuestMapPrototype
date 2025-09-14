// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestHUD.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"
#include "QuestMapPrototype/UI/FullMap/FullMapUserWidget.h"
#include "QuestMapPrototype/UI/GenericHUD/GenericHUDUserWidget.h"
#include "QuestMapPrototype/UI/Journal/JournalUserWidget.h"
#include "QuestMapPrototype/UI/VictoryWidget/VictoryUserWidget.h"


void AQuestHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowHUDWidget();
}

void AQuestHUD::ShowMapWidget()
{
	if (IsValid(JournalWidgetRef) )
	{
		if (JournalWidgetRef->IsInViewport())
		{
			ShowMapWidget();
		}
	}
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
	if (IsValid(FullMapWidgetRef) )
	{
		if (FullMapWidgetRef->IsInViewport())
		{
			return;
		}
	}
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
			PC->SetShowMouseCursor(true);
			PC->SetInputMode(FInputModeGameAndUI());
		}
		else
		{
			JournalWidgetRef->RemoveFromParent();
			PC->SetShowMouseCursor(false);
			PC->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AQuestHUD::ShowHUDWidget()
{
	AQuestMapPlayerController* PC = Cast<AQuestMapPlayerController>(GetOwningPlayerController()); 
	if (!IsValid(PC))
	{
		return;
	}
	if(!IsValid(HUDWidgetRef))
	{
		if(IsValid(HUDWidgetSubClass))
		{
			HUDWidgetRef = CreateWidget<UGenericHUDUserWidget>(PC, HUDWidgetSubClass);
		}
	}
	if (IsValid(HUDWidgetRef))
	{
		if(!HUDWidgetRef->IsInViewport())
		{
			HUDWidgetRef->AddToViewport();
		}
	}
}

void AQuestHUD::ShowVictoryWidget(bool bIsWin)
{
	AQuestMapPlayerController* PC = Cast<AQuestMapPlayerController>(GetOwningPlayerController()); 
	if (!IsValid(PC))
	{
		return;
	}
	if(!IsValid(VictoryWidgetRef))
	{
		if(IsValid(VictoryWidgetSubClass))
		{
			VictoryWidgetRef = CreateWidget<UVictoryUserWidget>(PC, VictoryWidgetSubClass);

			IsEnd = bIsWin;
		}
	}
	if (IsValid(VictoryWidgetRef))
	{
		if(!VictoryWidgetRef->IsInViewport())
		{
			VictoryWidgetRef->AddToViewport();
			VictoryWidgetRef->SetVictoryStatus(bIsWin);
		}
	}	
}
