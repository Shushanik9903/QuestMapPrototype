// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Kismet/KismetSystemLibrary.h"
#include "QuestHUD.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API AQuestHUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = true))
	TSubclassOf<class UFullMapUserWidget> FullMapSubClass = nullptr;
	
	UPROPERTY()
	TObjectPtr<class UFullMapUserWidget> FullMapWidgetRef = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = true))
	TSubclassOf<class UJournalUserWidget> JournalSubClass = nullptr;
	
	UPROPERTY()
	TObjectPtr<class UJournalUserWidget> JournalWidgetRef = nullptr;
	

	virtual void BeginPlay() override;
public:	
	UFUNCTION()
	void ShowMapWidget();
	
	UFUNCTION()
	void ShowJournalWidget();
};
