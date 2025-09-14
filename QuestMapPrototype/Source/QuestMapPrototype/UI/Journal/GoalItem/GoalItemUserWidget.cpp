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

void UGoalItemUserWidget::UpdateProperties(const EPickupType Type, const FPickupStats& Stats)
{
	PickupType = Type;

	const FString TypeString = UEnum::GetValueAsName(Type).ToString();
	FString LeftStr, RightStr;
	TypeString.Split("::", &LeftStr, &RightStr);
	const FString L_Status = FName::NameToDisplayString(RightStr, true);
	SetTextPropertyValue(TextType, L_Status);

	FString Info = FString::FromInt(Stats.Count) + TEXT("/") + FString::FromInt(Stats.Threshold);
	SetTextPropertyValue(TextInfo, Info);

	if (IsValid(Status))
	{
		const FLinearColor DynamicColor = FLinearColor::Green;
		const FLinearColor StaticColor = FLinearColor(1.f, 0.39f, 0.2f);
		Status->SetColorAndOpacity(Stats.bIsDynamic ? DynamicColor : StaticColor);
	}
}
