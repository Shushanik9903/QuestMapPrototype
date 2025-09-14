// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GenericHUDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API UGenericHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Transient, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<class UTextBlock> TextTime = nullptr;

	float PreviousSecond = 0.f;
	
	float CountdownTime = 0.f;

	double PreviousDeltaSecond = 0.f;

	bool bIsCountdownActive;

	void OnSecondElapsed(float Time);
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	virtual void NativeConstruct() override;

};
