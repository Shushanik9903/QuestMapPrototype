// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestGoal.generated.h"

/**
 * 
 */

 UENUM(BlueprintType)
enum class EGoalType : uint8
{
    Static,
    Dynamic
};

UCLASS(BlueprintType, Blueprintable)
class QUESTMAPPROTOTYPE_API UQuestGoal : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Goal")
    FString GoalName;

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Goal")
    EGoalType GoalType;

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Goal")
    TObjectPtr<class AActor> TargetActor = nullptr;
};
