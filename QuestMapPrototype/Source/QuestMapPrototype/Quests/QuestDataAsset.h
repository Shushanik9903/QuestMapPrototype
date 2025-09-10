// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestDataAsset.generated.h"



USTRUCT(BlueprintType)
struct FQuestEntry
{
    GENERATED_BODY()

public:
   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FString QuestName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FString Description;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<TObjectPtr<class UQuestGoal>> Goals;
};

UCLASS(BlueprintType)
class QUESTMAPPROTOTYPE_API UQuestDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<FQuestEntry> Quests;
	
};
