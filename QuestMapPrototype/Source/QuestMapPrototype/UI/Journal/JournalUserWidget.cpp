// Fill out your copyright notice in the Description page of Project Settings.


#include "JournalUserWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "GoalItem/GoalItemUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"

void UJournalUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BindActions();
	AdditionalMapQuestGoal = FPickupStats();
	if (IsValid(GridPanel))
	{
		GridPanel->ClearChildren();
	}
	if (IsValid(TextGoalCount) && IsValid(ButtonLeft) && IsValid(ButtonAdditionalGoal))
	{
		TextGoalCount->SetText(FText::FromString(FString::FromInt(AdditionalMapQuestGoal.Threshold)));
		ButtonLeft->SetIsEnabled(AdditionalMapQuestGoal.Threshold > 0);
		ButtonAdditionalGoal->SetIsEnabled(AdditionalMapQuestGoal.Threshold > 0);
	}
	if (UWorld* World = GetWorld())
	{
		if (AQuestGameMode* GM = Cast<AQuestGameMode>(UGameplayStatics::GetGameMode(World)))
		{
			GM->OnPickupStatsUpdated.AddUniqueDynamic(this, &UJournalUserWidget::OnPickupStatsUpdated_BP);

			for (const TPair<EPickupType, FPickupStats>& Pair : GM->PickupStats)
			{
				OnPickupStatsUpdated_BP(Pair.Key, Pair.Value);
			}
		}
	}
}

void UJournalUserWidget::OnPickupStatsUpdated_BP(EPickupType Type, const FPickupStats& Stats)
{
	AddOrUpdateGoal(Type, Stats);
}

void UJournalUserWidget::AddOrUpdateGoal(EPickupType Type, const FPickupStats& Stats)
{
	if (!IsValid(GridPanel)) return;

	for (UWidget* Child : GridPanel->GetAllChildren())
	{
		if (UGoalItemUserWidget* Goal = Cast<UGoalItemUserWidget>(Child))
		{
			if (Goal->PickupType == Type)
			{
				Goal->UpdateProperties(Type, Stats);
				return;
			}
		}
	}
	AddGoal(Type, Stats);
}

void UJournalUserWidget::AddGoal(EPickupType Type, const FPickupStats& Stats)
{
	if (!IsValid(GridPanel) || !IsValid(Item)) return;

	if (IsValid(VBoxRules))
	{
		VBoxRules->SetVisibility(ESlateVisibility::Visible);
	}

	const int32 NumChildren = GridPanel->GetAllChildren().Num();
	constexpr int32 NumColumns = 2;
	const int32 Column = NumChildren % NumColumns;
	const int32 Row = NumChildren / NumColumns;

	if (UGoalItemUserWidget* ItemRef = CreateWidget<UGoalItemUserWidget>(this, Item))
	{
		ItemRef->UpdateProperties(Type, Stats);
		UUniformGridSlot* ItemSlot = GridPanel->AddChildToUniformGrid(ItemRef, Row, Column);
		if (IsValid(ItemSlot))
		{
			EHorizontalAlignment ItemAlignment = (Column == 0) ? HAlign_Left : HAlign_Right;
			ItemSlot->SetHorizontalAlignment(ItemAlignment);
		}
	}
}

void UJournalUserWidget::OnButtonAddGoalClicked()
{
	if (AdditionalMapQuestGoal.Threshold == 0)
	{
		return;
	}
	EPickupType SelectedType = EPickupType::Star;
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		if (AQuestMapPlayerController* QuestPC = Cast<AQuestMapPlayerController>(PC))
		{
			QuestPC->Server_RequestAddMapGoal(SelectedType, AdditionalMapQuestGoal);
		}
	}
	if (IsValid(WidgetSwitcher)){WidgetSwitcher->SetActiveWidgetIndex(1);}
}

void UJournalUserWidget::OnButtonAddGoalHoverStateChanged()
{
	if (IsValid(ButtonAdditionalGoal) && IsValid(TextAdditionalGoal))
	{
		const FLinearColor HoverColor = FLinearColor::FromSRGBColor(FColor::FromHex(TEXT("F3F3F3")));
		const FLinearColor NormalColor = FColor::FromHex("FF6434");
		const FLinearColor Color = ButtonAdditionalGoal->IsHovered() ? HoverColor : NormalColor;
		TextAdditionalGoal->SetColorAndOpacity(Color);
	}
}

void UJournalUserWidget::OnButtonLeftClicked()
{
	AdditionalMapQuestGoal.Threshold = FMath::Max(0, AdditionalMapQuestGoal.Threshold - 1);

	if (!IsValid(TextGoalCount)) return;

	const bool bEnableLeft = AdditionalMapQuestGoal.Threshold > 0;
	if (IsValid(ButtonAdditionalGoal))
	{
		ButtonAdditionalGoal->SetIsEnabled(bEnableLeft);
	}
	if (IsValid(ButtonLeft) && ButtonLeft->GetIsEnabled() != bEnableLeft)
	{
		ButtonLeft->SetIsEnabled(bEnableLeft);
	}
	TextGoalCount->SetText(FText::AsNumber(AdditionalMapQuestGoal.Threshold));
}

void UJournalUserWidget::OnButtonRightClicked()
{
	if (!IsValid(TextGoalCount)) return;
	AdditionalMapQuestGoal.Threshold++;
	const bool bEnableLeft = AdditionalMapQuestGoal.Threshold > 0;
	if (IsValid(ButtonLeft) && ButtonLeft->GetIsEnabled() != bEnableLeft)
	{
		ButtonLeft->SetIsEnabled(bEnableLeft);
	}
	if (IsValid(ButtonAdditionalGoal))
	{
		ButtonAdditionalGoal->SetIsEnabled(bEnableLeft);
	}
	TextGoalCount->SetText(FText::AsNumber(AdditionalMapQuestGoal.Threshold));
}


void UJournalUserWidget::OnDynamicStateChanged(bool bIsChecked) { AdditionalMapQuestGoal.bIsDynamic = bIsChecked; }

void UJournalUserWidget::BindActions()
{
	if (IsValid(DynamicCheck))
	{
		DynamicCheck->OnCheckStateChanged.AddUniqueDynamic(this, &ThisClass::OnDynamicStateChanged);
	}
	if (IsValid(ButtonLeft)) { ButtonLeft->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonLeftClicked); }
	if (IsValid(ButtonRight)) { ButtonRight->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonRightClicked); }
	if (IsValid(ButtonAdditionalGoal))
	{
		ButtonAdditionalGoal->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalClicked);
		ButtonAdditionalGoal->OnHovered.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalHoverStateChanged);
		ButtonAdditionalGoal->OnUnhovered.AddUniqueDynamic(this, &ThisClass::OnButtonAddGoalHoverStateChanged);
	}
}
