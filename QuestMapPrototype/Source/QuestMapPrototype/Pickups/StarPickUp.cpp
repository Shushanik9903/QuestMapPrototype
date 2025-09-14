// Fill out your copyright notice in the Description page of Project Settings.


#include "StarPickUp.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"

// Sets default values
AStarPickUp::AStarPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	checkf(RootComponent != nullptr, TEXT("RootComponent is nullptr"));

	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	checkf(OverlapSphere != nullptr, TEXT("OverlapSphere is nullptr"));
	OverlapSphere->SetupAttachment(RootComponent);
	OverlapSphere->SetSphereRadius(150.f);
	OverlapSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	OverlapSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	OverlapSphere->AddLocalOffset(FVector(0.f, 0.f, 85.f));

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	checkf(PickupMesh != nullptr, TEXT("PickupMesh is nullptr"));
	PickupMesh->SetupAttachment(OverlapSphere);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PickupMesh->SetRelativeScale3D(FVector(5.f, 5.f, 5.f));
	PickupMesh->SetRenderCustomDepth(true);
	PickupMesh->SetCustomDepthStencilValue(250);

	PickupEffectComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PickupEffectComponent"));
	checkf(PickupEffectComponent != nullptr, TEXT("PickupEffectComponent is nullptr"));
	PickupEffectComponent->SetupAttachment(RootComponent);

	Icon = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Icon"));
	checkf(Icon != nullptr, TEXT("The Icon is nullptr"));
	Icon->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AStarPickUp::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		GetWorldTimerManager().SetTimer(
			BindOverlapTimer,
			this,
			&AStarPickUp::BindOverlapTimerFinished,
			BindOverlapTime
		);

		Icon->SetHiddenInGame(true);
	}

	
}

void AStarPickUp::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor) return;

	AQuestGameMode* GM = Cast<AQuestGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GM)
	{
		//GM->RegisterPickup(PickupType);
	}
	Destroy();
}

void AStarPickUp::BindOverlapTimerFinished()
{
	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &AStarPickUp::OnSphereOverlap);
}

void AStarPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PickupMesh)
	{
		PickupMesh->AddWorldRotation(FRotator(0.f, BaseTurnRate * DeltaTime, 0.f));
	}
}

void AStarPickUp::Destroyed()
{
	Super::Destroyed();

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			this,
			PickupSound,
			GetActorLocation()
		);
	}
	if (PickupEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			PickupEffect,
			GetActorLocation(),
			GetActorRotation()
		);
	}
}

void AStarPickUp::ShowIcon(bool bshow)
{
	Icon->SetHiddenInGame(!bshow);
}

