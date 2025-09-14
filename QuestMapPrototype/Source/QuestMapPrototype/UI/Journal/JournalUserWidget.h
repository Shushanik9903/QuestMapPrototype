// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	TObjectPtr<class UTextBlock> TextStartGame = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextRemoveGoal  = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonAdditionalGoal = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonRemoveGoal = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonStartGame = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonLeft = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UButton> ButtonRight = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UCheckBox> DynamicCheck = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextGoalCount = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class USizeBox> BoxRemoveGoal = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UVerticalBox> BoxAdditionalGoal = nullptr;
	
	UFUNCTION()
	void OnButtonStartHoverStateChanged();

	UFUNCTION()
	void OnButtonAddGoalClicked();

	UFUNCTION()
	void OnButtonStartClicked();
	
	UFUNCTION()
	void OnButtonAddGoalHoverStateChanged();

	UFUNCTION()
	void OnButtonLeftClicked();
	
	UFUNCTION()
	void OnButtonRightClicked();
	
	UFUNCTION()
	void OnButtonRemoveHoverStateChanged();
	
	UFUNCTION()
	void OnButtonRemoveGoalClicked();

	UFUNCTION()
	void OnDynamicStateChanged(bool bIsChecked);
	
	UFUNCTION()
	void BindActions();

	FMapQuestGoal AdditionalMapQuestGoal = FMapQuestGoal();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UGoalItemUserWidget> Item = nullptr;

	UFUNCTION()
	void AddGoals(const FMapQuestGoal& Goal);
	
};

