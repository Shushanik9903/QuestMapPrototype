// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupIconInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPickupIconInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class QUESTMAPPROTOTYPE_API IPickupIconInterface
{
	GENERATED_BODY()

	
public:

	virtual void ShowIcon(bool bShow) = 0;
};
