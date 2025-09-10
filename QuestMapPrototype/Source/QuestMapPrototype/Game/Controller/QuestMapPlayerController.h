// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QuestMapPlayerController.generated.h"

/**
 * 
 */

 UENUM(BlueprintType)
enum class EQuestName : uint8
{
    Banana,
    Strawberry,
    Orange
};

USTRUCT(BlueprintType)
struct FQuestProgress
{
    GENERATED_BODY()

public:
   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    EQuestName QuestName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    int32 QuestCount = 0;
};

UCLASS()
class QUESTMAPPROTOTYPE_API AQuestMapPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<FQuestProgress> Quests;
};
