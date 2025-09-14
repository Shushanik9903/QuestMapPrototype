// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalItemUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"

void UGoalItemUserWidget::SetTextPropertyValue(UTextBlock* TextB, const FString& Value)
{
	if (IsValid(TextB))
	{
		TextB->SetText(FText::FromString(Value));
	}
}

void UGoalItemUserWidget::UpdateProperties(const FMapQuestGoal& Goal)
{
	if (StaticEnum<EPickupType>())
	{
		const FString NameString = StaticEnum<EPickupType>()->GetNameStringByValue((int64)Goal.PickupType);
		const FString Display = FName::NameToDisplayString(NameString, true);
		SetTextPropertyValue(TextType, Display);
	}
	else
	{
		SetTextPropertyValue(TextType, TEXT("Unknown"));
	}

	const FString Info = FString::FromInt(Goal.CollectedCount) + TEXT("/") + FString::FromInt(Goal.MaxCount);
	SetTextPropertyValue(TextInfo, Info);

	if (IsValid(Status))
	{
		const FLinearColor DynamicColor = FColor::Green;
		const FLinearColor StaticColor = FColor::FromHex("FF6434"); 
		Status->SetColorAndOpacity(Goal.bIsDynamic ? DynamicColor : StaticColor);
	}
}