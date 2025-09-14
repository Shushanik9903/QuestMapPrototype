// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "GoalItemUserWidget.generated.h"

/**
 * 
 */
UCLASS() class QUESTMAPPROTOTYPE_API UGoalItemUserWidget : public UUserWidget { GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget))
	TObjectPtr<class UTextBlock> TextType = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextInfo = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget))
	TObjectPtr<class UImage> Status = nullptr;

	void SetTextPropertyValue(UTextBlock* TextB, const FString& Value);
	
public:
	UFUNCTION()
	void UpdateProperties(const EPickupType Type, const FPickupStats& Stats);

	UPROPERTY(BlueprintReadOnly)
	EPickupType PickupType = EPickupType::None;
};
