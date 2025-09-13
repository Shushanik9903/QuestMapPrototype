// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMapPlayerController.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "QuestMapPrototype/HUD/QuestHUD.h"
#include "QuestMapPrototype/Pickups/Pickup.h"
#include "QuestMapPrototype/QuestMapPrototypeCharacter.h"

void AQuestMapPlayerController::ShowAllPickupIcons(bool bShow)
{
    TArray<AActor*> FoundCoins;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APickup::StaticClass(), FoundCoins);

    for (AActor* Actor : FoundCoins)
    {
        if (APickup* PickupActor = Cast<APickup>(Actor))
        {
            PickupActor->ShowIcon(bShow);
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
