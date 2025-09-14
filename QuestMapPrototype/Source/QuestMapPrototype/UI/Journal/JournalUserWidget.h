// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoalItem/GoalItemUserWidget.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "JournalUserWidget.generated.h"

/**
 * 
 */

UCLASS()
class QUESTMAPPROTOTYPE_API UJournalUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UUniformGridPanel> GridPanel = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UVerticalBox> VBoxRules = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextAdditionalGoal = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonAdditionalGoal = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonLeft = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonRight = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UCheckBox> DynamicCheck = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextGoalCount = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UVerticalBox> BoxAdditionalGoal = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UWidgetSwitcher> WidgetSwitcher = nullptr;

	UFUNCTION()
	void OnPickupStatsUpdated_BP(EPickupType Type, const FPickupStats& Stats);

	UFUNCTION()
	void AddOrUpdateGoal(EPickupType Type, const FPickupStats& Stats);

	UFUNCTION()
	void AddGoal(EPickupType Type, const FPickupStats& Stats);

	UFUNCTION()
	void OnButtonAddGoalClicked();

	UFUNCTION()
	void OnButtonAddGoalHoverStateChanged();

	UFUNCTION()
	void OnButtonLeftClicked();

	UFUNCTION()
	void OnButtonRightClicked();

	UFUNCTION()
	void OnDynamicStateChanged(bool bIsChecked);

	UFUNCTION()
	void BindActions();
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGoalItemUserWidget> Item = nullptr;
	
	FPickupStats AdditionalMapQuestGoal;
};

