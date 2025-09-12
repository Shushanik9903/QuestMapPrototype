// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"
#include "QuestMapPrototype/QuestMapPrototypeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AHealthPickup::AHealthPickup()
{
	bReplicates = true;
    PrimaryActorTick.bCanEverTick = false;
}

void AHealthPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (!IsValid(OtherActor) && OtherActor == this) return;

    if (AQuestMapPrototypeCharacter* L_Character = Cast<AQuestMapPrototypeCharacter>(OtherActor);IsValid(L_Character))
    {
       
        L_Character->GetCharacterMovement()->MaxWalkSpeed = 1000.f;

        L_Character->GetWorldTimerManager().ClearTimer(L_Character->SpeedResetTimer);

        L_Character->GetWorldTimerManager().SetTimer(
            L_Character->SpeedResetTimer,
            [L_Character]()
            {
                if (IsValid(L_Character))
                {
                    L_Character->GetCharacterMovement()->MaxWalkSpeed = 500.f;
                }
            },
            10.f, false);

        Destroy();
    }

}

void AHealthPickup::MoveToLocation(const FVector& NewLocation)
{
       SetActorLocation(NewLocation);
}

void AHealthPickup::BeginPlay()
{
       Super::BeginPlay();
}

