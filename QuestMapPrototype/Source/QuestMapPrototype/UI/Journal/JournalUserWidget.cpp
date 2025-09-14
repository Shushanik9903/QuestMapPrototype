// Fill out your copyright notice in the Description page of Project Settings.


#include "JournalUserWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "GoalItem/GoalItemUserWidget.h"

void UJournalUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BindActions();
	if (!IsValid(GridPanel))
	{
		GridPanel->ClearChildren();
	}
	FMapQuestGoal CoinGoal;
	CoinGoal.MaxCount = 20;
	CoinGoal.PickupType = EPickupType::Coin;
	CoinGoal.bIsDynamic = true;
	AddGoals(CoinGoal); 

	FMapQuestGoal ShieldGoal;
	ShieldGoal.MaxCount = 1;
	ShieldGoal.PickupType = EPickupType::Shield;
	ShieldGoal.bIsDynamic = false;
	AddGoals(ShieldGoal);
	
	FMapQuestGoal ShieldGoald;
	ShieldGoald.MaxCount = 1;
	ShieldGoald.PickupType = EPickupType::Shield;
	ShieldGoald.bIsDynamic = false;
	AddGoals(ShieldGoald);
}

void UJournalUserWidget::AddGoals(const FMapQuestGoal& Goal)
{
	if (!IsValid(GridPanel))
	{
		return;
	}

	if (IsValid(VBoxRules))
	{
		VBoxRules->SetVisibility(ESlateVisibility::Visible);
	}

	const int32 NumChildren = GridPanel->GetAllChildren().Num();
	const int32 NumColumns = 2;
	const int32 Column = NumChildren % NumColumns;
	const int32 Row = NumChildren / NumColumns;

	if (IsValid(Item))
	{
		UGoalItemUserWidget* ItemRef = CreateWidget<UGoalItemUserWidget>(this, Item);
		if (IsValid(ItemRef))
		{
			ItemRef->UpdateProperties(Goal);

			UUniformGridSlot* ItemSlot = GridPanel->AddChildToUniformGrid(ItemRef, Row, Column);
			if (IsValid(ItemSlot))
			{
				EHorizontalAlignment ItemAlignment = (Column == 0) ? HAlign_Left : HAlign_Right;
				ItemSlot->SetHorizontalAlignment(ItemAlignment);
			}
		}
	}
}

void UJournalUserWidget::OnButtonStartHoverStateChanged()
{
	if (IsValid(ButtonStartGame) && IsValid(TextStartGame))
	{
		FColor Color = ButtonStartGame->IsHovered() ? FColor::FromHex("F3F3F3") : FColor::FromHex("FF2009FF");
		TextStartGame->SetColorAndOpacity(Color);
	}
}

void UJournalUserWidget::OnButtonAddGoalClicked()
{
}

void UJournalUserWidget::OnButtonStartClicked()
{
	RemoveFromParent();
	//TODO
}

void UJournalUserWidget::OnButtonAddGoalHoverStateChanged()
{
	if (IsValid(ButtonAdditionalGoal) && IsValid(TextAdditionalGoal))
	{
		FColor Color = ButtonAdditionalGoal->IsHovered() ? FColor::FromHex("F3F3F3") : FColor::FromHex("FF2009FF");
		TextAdditionalGoal->SetColorAndOpacity(Color);
	}
}

void UJournalUserWidget::BindActions()
{
	if(IsValid(ButtonStartGame))
	{
		ButtonStartGame->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonStartClicked);
		ButtonStartGame->OnHovered.AddUniqueDynamic(this, &ThisClass::OnButtonStartHoverStateChanged);
		ButtonStartGame->OnUnhovered.AddUniqueDynamic(this, &ThisClass::OnButtonStartHoverStateChanged);
	}
	if(IsValid(ButtonAdditionalGoal))
	{
		ButtonAdditionalGoal->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalClicked);
		ButtonAdditionalGoal->OnHovered.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalHoverStateChanged);
		ButtonAdditionalGoal->OnUnhovered.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalHoverStateChanged);
	}
}
