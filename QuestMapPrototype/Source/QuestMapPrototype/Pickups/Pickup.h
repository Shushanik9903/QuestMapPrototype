// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestMapPrototype/GameMode/QuestGameMode.h"
#include "Pickup.generated.h"


UCLASS()
class QUESTMAPPROTOTYPE_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	APickup();
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UPROPERTY(EditAnywhere)
	float BaseTurnRate = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	EPickupType PickupType = EPickupType::None;

private:
	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<class USphereComponent> OverlapSphere;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<class USoundCue> PickupSound;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<class UStaticMeshComponent> PickupMesh;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	TObjectPtr<class UNiagaraComponent> PickupEffectComponent;

	UPROPERTY(EditAnywhere, Category = "Pickup")
	TObjectPtr<class UNiagaraSystem> PickupEffect;

	FTimerHandle BindOverlapTimer;
	float BindOverlapTime = 0.25f;
	void BindOverlapTimerFinished();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sprite")
	TObjectPtr<class UPaperSpriteComponent> Icon;

	UFUNCTION(BlueprintCallable)
	void ShowIcon(bool bshow);

	UFUNCTION()
	void InitializeQuestMapPlayerController();  

};
