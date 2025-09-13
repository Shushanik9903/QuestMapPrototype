// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QuestMapPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class QUESTMAPPROTOTYPE_API AQuestMapPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UInputAction> ShowMapAction = nullptr;


	UPROPERTY(EditAnywhere)
	TObjectPtr<class UInputAction> ShowJournalAction = nullptr;

	UPROPERTY(EditAnywhere)
	class UInputMappingContext* InputContext = nullptr;

	UFUNCTION()
	void ShowMapWidget();

	UFUNCTION()
	void ShowJournalWidget();

	UFUNCTION()
	void SetInputContext();

	UPROPERTY()
	class UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = nullptr;
	
	UFUNCTION(BlueprintCallable)
	void ShowAllPickupIcons(bool bShow);

	UPROPERTY()
	TObjectPtr<class APickup> Pickup = nullptr;
	
};
