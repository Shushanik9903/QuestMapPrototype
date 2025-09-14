// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericHUDUserWidget.h"
#include "Components/TextBlock.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"
#include "QuestMapPrototype/HUD/QuestHUD.h"

void UGenericHUDUserWidget::OnSecondElapsed(float Time)
{
	if(IsValid(TextTime))
	{
		Time = FMath::Max(Time, 0.0f);
		const int32 NumMinutes = FMath::FloorToInt(Time/60.f);
		const int32 NumSeconds = FMath::FloorToInt(Time-(NumMinutes*60.f));
		FString TimeString = FString::Printf(TEXT("%02d:%02d"), NumMinutes, NumSeconds);
		
		TextTime->SetText(FText::FromString(TimeString));
	}
}

void UGenericHUDUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (bIsCountdownActive)
	{
		double CurrentDeltaSecond = FPlatformTime::Seconds();
		float Delta = CurrentDeltaSecond - PreviousDeltaSecond;
		CountdownTime -= Delta;
		PreviousDeltaSecond = CurrentDeltaSecond;

		float CurrentSecond = CountdownTime;

		if (CurrentSecond != PreviousSecond && CurrentSecond > 0.f)
		{
			OnSecondElapsed(CurrentSecond);
			PreviousSecond = CurrentSecond;
		}
		if (FMath::IsNearlyZero(CountdownTime) || CountdownTime < 0.f)
		{
			bIsCountdownActive = false;
			if (AQuestMapPlayerController* PC = GetOwningPlayer<AQuestMapPlayerController>())
			{
				if (AQuestHUD* QuestHUD = Cast<AQuestHUD>(PC->GetHUD()))
				{
					QuestHUD->ShowVictoryWidget(false);
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("Countdown completed!"));
		}
	}
}

void UGenericHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	OnSecondElapsed(18.f); // min
	PreviousDeltaSecond =  FPlatformTime::Seconds();
	CountdownTime = 18.f;
	bIsCountdownActive = true;
	PreviousSecond = CountdownTime;
}
