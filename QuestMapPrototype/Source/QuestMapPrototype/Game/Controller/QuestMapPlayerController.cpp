// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMapPlayerController.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "QuestMapPrototype/HUD/QuestHUD.h"
#include "QuestMapPrototype/Pickups/Pickup.h"
#include "QuestMapPrototype/Pickups/StarPickUp.h"
#include "QuestMapPrototype/QuestMapPrototypeCharacter.h"
#include "QuestMapPrototype/Interface/PickupIconInterface.h"

void AQuestMapPlayerController::ShowAllPickupIcons(bool bShow)
{
    TArray<AActor*> FoundActors;
    
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        if (IPickupIconInterface* PickupInterface = Cast<IPickupIconInterface>(Actor))
        {
            PickupInterface->ShowIcon(bShow);
        }
    }
}

void AQuestMapPlayerController::SetCamera(ACameraActor* NewCamera)
{
    if(!IsValid(NewCamera)) return;

    Camera = NewCamera;
}

void AQuestMapPlayerController::SetQuestMapCharacter()
{
    if(APawn * L_Pawn = GetPawn())
    {
		QuestMapPrototypeCharacter = Cast<AQuestMapPrototypeCharacter>(L_Pawn);
		if (!IsValid(QuestMapPrototypeCharacter)) return;
        
    }
}

void AQuestMapPlayerController::BeginPlay()
{
       Super::BeginPlay();
       SetInputContext();
       SetQuestMapCharacter();
}

void AQuestMapPlayerController::SetupInputComponent()
{
       Super::SetupInputComponent();
       if (IsValid(InputComponent))
       {
               if (UEnhancedInputComponent* EnhancedInputComp = CastChecked<UEnhancedInputComponent>(InputComponent))
               {
                       EnhancedInputComp->ClearActionBindings();
                       EnhancedInputComp->ClearAxisBindings();
                       EnhancedInputComp->ClearActionEventBindings();
                       EnhancedInputComp->ClearActionValueBindings();

                       EnhancedInputComp->BindAction(ShowMapAction, ETriggerEvent::Started, this, &AQuestMapPlayerController::ShowMapWidget);
                       EnhancedInputComp->BindAction(ShowMapAction, ETriggerEvent::Completed, this, &AQuestMapPlayerController::ReturnToCharacterView);
                       EnhancedInputComp->BindAction(ShowJournalAction, ETriggerEvent::Started, this, &AQuestMapPlayerController::ShowJournalWidget);
               }
       }
}

void AQuestMapPlayerController::ShowMapWidget()
{
    if(!IsValid(Camera)) return;

    SetViewTargetWithBlend(Camera, 0.5f);
    ShowAllPickupIcons(true);
 
}

void AQuestMapPlayerController::ReturnToCharacterView()
{
    if (!IsValid(QuestMapPrototypeCharacter)) return;

    SetViewTargetWithBlend(QuestMapPrototypeCharacter, 0.5f);
    ShowAllPickupIcons(false);
}

void AQuestMapPlayerController::Server_RequestAddMapGoal_Implementation(EPickupType Type, const FPickupStats& Goal)
{
	if (AQuestGameMode* GM = Cast<AQuestGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GM->AddMapQuestGoal(Type, Goal);
	}
}

void AQuestMapPlayerController::ShowJournalWidget()
{
	AQuestHUD* QuestHUD = GetHUD<AQuestHUD>();
	if (IsValid(QuestHUD))
	{
		QuestHUD->ShowJournalWidget();
	}
}

void AQuestMapPlayerController::SetInputContext()
{
       if (GetLocalPlayer())
       {
               EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
               if (EnhancedInputSubsystem)
               {
                       if (InputContext)
                       {
                               if (!EnhancedInputSubsystem->HasMappingContext(InputContext))
                               {
                                       EnhancedInputSubsystem->AddMappingContext(InputContext, 0);
                               }
                       }
               }
       }
}
