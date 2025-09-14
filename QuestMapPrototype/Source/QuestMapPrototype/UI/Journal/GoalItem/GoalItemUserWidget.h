// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoalItemUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API UGoalItemUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextType = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextInfo = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UImage> Status = nullptr;

	void SetTextPropertyValue(UTextBlock* TextB, const FString& Value);

public:
	UFUNCTION()
	void UpdateProperties(const FMapQuestGoal& Goal);

};
