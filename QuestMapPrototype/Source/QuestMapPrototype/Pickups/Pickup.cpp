// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"

APickup::APickup()
{
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

void APickup::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		GetWorldTimerManager().SetTimer(
			BindOverlapTimer,
			this,
			&APickup::BindOverlapTimerFinished,
			BindOverlapTime
		);

		Icon->SetHiddenInGame(true);
		InitializeQuestMapPlayerController();
	}
}

void APickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!HasAuthority() || !OtherActor || PickupType == EPickupType::None) return;
	if (AQuestGameMode* GM = Cast<AQuestGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GM->RegisterPickup(PickupType);
		bool bAllReached = true;
		bool bHasRelevantEntries = false;
		for (const TPair<EPickupType, FPickupStats>& Pair : GM->PickupStats)
		{
			if (Pair.Key != EPickupType::Coin || Pair.Key == EPickupType::Star) continue;
			if (Pair.Value.Threshold <= 0)
			{
				continue;
			}
			bHasRelevantEntries = true;
			int32 Required = Pair.Value.Threshold;
			if (Pair.Value.Count < Required)
			{
				bAllReached = false;
				break;
			}
		}
		if (bHasRelevantEntries && bAllReached)
		{
			if (GM->OnShieldSpawn.IsBound())
			{
				GM->OnShieldSpawn.Broadcast(FVector::ZeroVector);
			}
		}
	}

	Destroy();
}

void APickup::BindOverlapTimerFinished()
{
	if (OverlapSphere)
	{
		OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnSphereOverlap);
	}
}

void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PickupMesh)
	{
		PickupMesh->AddWorldRotation(FRotator(0.f, BaseTurnRate * DeltaTime, 0.f));
	}
}

void APickup::Destroyed()
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

void APickup::ShowIcon(bool bshow)
{
	Icon->SetHiddenInGame(!bshow);
}

void APickup::InitializeQuestMapPlayerController()
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);IsValid(PC))
	{
		if (AQuestMapPlayerController* QuestPC = Cast<AQuestMapPlayerController>(PC);IsValid(QuestPC))
		{
			QuestPC->Pickup = this;
		}
	}
}
