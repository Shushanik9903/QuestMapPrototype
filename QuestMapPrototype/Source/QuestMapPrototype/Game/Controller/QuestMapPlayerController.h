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

public:
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

	UFUNCTION(BlueprintCallable)

	void SetCamera(class ACameraActor* NewCamera);

	UFUNCTION()
	void SetQuestMapCharacter();

	UFUNCTION()
	void ReturnToCharacterView();

	UFUNCTION(Server, Reliable)
	void Server_RequestAddMapGoal(EPickupType Type, const FPickupStats& Goal);
public:
	UPROPERTY()
	TObjectPtr<class APickup> Pickup = nullptr; 


	TObjectPtr<class ACameraActor> Camera = nullptr;
	
	UPROPERTY()
	TObjectPtr<class AQuestMapPrototypeCharacter> QuestMapPrototypeCharacter = nullptr;
};
