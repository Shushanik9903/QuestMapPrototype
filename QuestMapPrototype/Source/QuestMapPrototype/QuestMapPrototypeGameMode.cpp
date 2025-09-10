// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestMapPrototypeGameMode.h"
#include "QuestMapPrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQuestMapPrototypeGameMode::AQuestMapPrototypeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
