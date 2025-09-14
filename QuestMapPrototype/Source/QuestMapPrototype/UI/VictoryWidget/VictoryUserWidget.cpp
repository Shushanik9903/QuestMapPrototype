// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryUserWidget.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"

void UVictoryUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(IsValid(VictoryAnimStart))
	{
		StartAnimationDelegate.BindDynamic(this, &UVictoryUserWidget::StartAnimationFinished);
		BindToAnimationFinished(VictoryAnimStart, StartAnimationDelegate);
	}
	if(IsValid(VictoryAnimStart))
	{
		PlayAnimationForward(VictoryAnimStart);
	}
	AQuestMapPlayerController* PC = GetOwningPlayer<AQuestMapPlayerController>();
	if (IsValid(PC))
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().ClearAllTimersForObject(GetWorld());
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			[&, this]()
			{
				if (IsAnimationPlaying(VictoryAnimLoop))
				{
					StopAnimation(VictoryAnimLoop);
				}
				UKismetSystemLibrary::QuitGame(
					this,
					PC,
					EQuitPreference::Quit,
					false
				);
			},
			10.0f,
			false
		);
	}
}

void UVictoryUserWidget::StartAnimationFinished()
{
	if(IsValid(VictoryAnimLoop))
	{
		PlayAnimation(VictoryAnimLoop,0,0);
	}
}

void UVictoryUserWidget::SetVictoryStatus(bool bIsWin) const
{
	FColor Color = bIsWin ? FColor::FromHex("016E6E"): FColor::FromHex("FF3434");
	if (IsValid(Border))
	{
		Border->SetContentColorAndOpacity(Color);
	}
	FString Text = bIsWin ? "You Win!" : "You Lose!";
	if (IsValid(TextStatus))
	{
		TextStatus->SetText(FText::FromString(Text));

	}

	if (UWorld* World = GetWorld())
	{
		FTimerHandle TimerHandle;
		World->GetTimerManager().SetTimer(
			TimerHandle,
			FTimerDelegate::CreateLambda([World]()
				{
					
					FString CurrentLevelName = World->GetMapName();
					CurrentLevelName.RemoveFromStart(World->StreamingLevelsPrefix); 
					UGameplayStatics::OpenLevel(World, FName(*CurrentLevelName));
				}),
			3.0f,
			false
		);
	}
}
