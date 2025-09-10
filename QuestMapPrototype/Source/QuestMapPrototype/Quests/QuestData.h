// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class QUESTMAPPROTOTYPE_API UQuestData : public UObject
{
	GENERATED_BODY()

public:
   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FString QuestName;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FString Description;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<class UQuestGoal*> Goals;
};
