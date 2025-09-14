// Fill out your copyright notice in the Description page of Project Settings.


#include "JournalUserWidget.h"

#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "GoalItem/GoalItemUserWidget.h"

void UJournalUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BindActions();
	AdditionalMapQuestGoal = FMapQuestGoal();
	if (!IsValid(GridPanel))
	{
		GridPanel->ClearChildren();
	}
	//TODo Gevor read data from gamemode and add it to grid call AddGoals
	if (IsValid(BoxRemoveGoal))
	{
		BoxRemoveGoal->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (IsValid(BoxAdditionalGoal))
	{
		BoxAdditionalGoal->SetVisibility(ESlateVisibility::Collapsed);
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
	if (AdditionalMapQuestGoal.MaxCount > 0 )
	{
		ButtonAdditionalGoal->SetVisibility(ESlateVisibility::Hidden);
		BoxAdditionalGoal->SetVisibility(ESlateVisibility::Collapsed);
		BoxRemoveGoal->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	if (IsValid(BoxAdditionalGoal) && IsValid(BoxRemoveGoal))
	{
		BoxAdditionalGoal->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		BoxRemoveGoal->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void UJournalUserWidget::OnButtonStartClicked()
{
	RemoveFromParent();

	
	//TODO Gevor brodcast to start countdown in GenericHUD
}

void UJournalUserWidget::OnButtonAddGoalHoverStateChanged()
{
	if (IsValid(ButtonAdditionalGoal) && IsValid(TextAdditionalGoal))
	{
		FColor Color = ButtonAdditionalGoal->IsHovered() ? FColor::FromHex("F3F3F3") : FColor::FromHex("FF2009FF");
		TextAdditionalGoal->SetColorAndOpacity(Color);
	}
}

void UJournalUserWidget::OnButtonLeftClicked()
{
	AdditionalMapQuestGoal.MaxCount--;
	if(!IsValid(TextGoalCount))
	{
		return;
	}
	bool bEnable = AdditionalMapQuestGoal.MaxCount > 0;
	if (ButtonLeft->GetIsEnabled() != bEnable)
	{
		ButtonLeft->SetIsEnabled(bEnable);
	}
	TextGoalCount->SetText(FText::FromString(FString::FromInt(AdditionalMapQuestGoal.MaxCount)));
}

void UJournalUserWidget::OnButtonRightClicked()
{
	AdditionalMapQuestGoal.MaxCount++;
	if(!IsValid(TextGoalCount))
	{
		return;
	}
	const bool bEnable = AdditionalMapQuestGoal.MaxCount> 0;
	if (ButtonLeft->GetIsEnabled() != bEnable)
	{
		ButtonLeft->SetIsEnabled(bEnable);
	}
	TextGoalCount->SetText(FText::FromString(FString::FromInt(AdditionalMapQuestGoal.MaxCount)));
}

void UJournalUserWidget::OnButtonRemoveHoverStateChanged()
{
	if (IsValid(ButtonRemoveGoal) && IsValid(TextRemoveGoal))
	{
		FColor Color = ButtonRemoveGoal->IsHovered() ? FColor::Red : FColor::FromHex("FF2009FF");
		TextAdditionalGoal->SetColorAndOpacity(Color);
	}
}

void UJournalUserWidget::OnButtonRemoveGoalClicked()
{
	if (IsValid(BoxAdditionalGoal) && IsValid(BoxRemoveGoal))
	{
		BoxAdditionalGoal->SetVisibility(ESlateVisibility::Collapsed);
		BoxRemoveGoal->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UJournalUserWidget::OnDynamicStateChanged(bool bIsChecked)
{
	AdditionalMapQuestGoal.bIsDynamic = bIsChecked;
}

void UJournalUserWidget::BindActions()
{
	if (IsValid(DynamicCheck))
	{
		DynamicCheck->OnCheckStateChanged.AddUniqueDynamic(this, &ThisClass::OnDynamicStateChanged);
	}
	if(IsValid(ButtonLeft))
	{
		ButtonLeft->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonLeftClicked);
	}
	if(IsValid(ButtonRight))
	{
		ButtonRight->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonRightClicked);
	}
	if(IsValid(ButtonRemoveGoal))
	{
		ButtonRemoveGoal->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonRemoveGoalClicked);
		ButtonRemoveGoal->OnHovered.AddUniqueDynamic(this, &ThisClass::OnButtonRemoveHoverStateChanged);
		ButtonRemoveGoal->OnUnhovered.AddUniqueDynamic(this, &ThisClass::OnButtonRemoveHoverStateChanged);
	}
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
