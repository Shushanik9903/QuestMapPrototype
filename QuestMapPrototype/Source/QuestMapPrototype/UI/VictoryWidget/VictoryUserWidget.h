// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VictoryUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API UVictoryUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	UFUNCTION()
	void StartAnimationFinished();
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnim, AllowPrivateAccess = true))
	TObjectPtr<class UWidgetAnimation> VictoryAnimStart = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnim, AllowPrivateAccess = true))
	TObjectPtr<class UWidgetAnimation> VictoryAnimLoop = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UBorder> Border = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextStatus = nullptr;
	
	FWidgetAnimationDynamicEvent StartAnimationDelegate;

public:
	UFUNCTION()
	void SetVictoryStatus(bool bIsWin);

	FTimerHandle RestartTimerHandle;

	UFUNCTION()
	void RestartLevel();
};
