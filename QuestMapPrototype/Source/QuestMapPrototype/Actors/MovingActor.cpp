// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"
#include "Components/SplineMeshComponent.h"
#include "Components/SplineComponent.h"

// Sets default values
AMovingActor::AMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

    SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    checkf(SplineComponent != nullptr, TEXT("The SplineComponent is nullptr"));
    SplineComponent->SetupAttachment(RootComponent);
 }

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Super::Tick(DeltaTime);

    if (!IsValid(SplineComponent)) return;

   
    CurrentDistance += MoveSpeed * DeltaTime;

  
    float SplineLength = SplineComponent->GetSplineLength();
    if (CurrentDistance >= SplineLength)
    {
        CurrentDistance = SplineLength;

      
        UE_LOG(LogTemp, Warning, TEXT("Reached the end of the spline!"));

        return;
    }

    FVector NewLocation = SplineComponent->GetLocationAtDistanceAlongSpline(CurrentDistance, ESplineCoordinateSpace::World);
    SetActorLocation(NewLocation);
}

