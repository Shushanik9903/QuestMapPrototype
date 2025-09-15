// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "QuestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API UQuestGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinCount = 12;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 EnergyCount = 10;	
};
