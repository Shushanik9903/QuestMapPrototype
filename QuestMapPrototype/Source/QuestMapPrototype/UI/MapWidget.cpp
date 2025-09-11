// Fill out your copyright notice in the Description page of Project Settings.

#include "MapWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/SplineComponent.h"
#include "EngineUtils.h"    
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

void UMapWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (UWorld* World = GetWorld())
    {
        WorldBounds = CalculateLevelBounds(World);
        UE_LOG(LogTemp, Log, TEXT("MapWidget: World bounds Min=%s Max=%s"),
            *WorldBounds.Min.ToString(), *WorldBounds.Max.ToString());
    }
}

FReply UMapWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    const FVector2D LocalClick = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
    const FVector2D MapSize = InGeometry.GetLocalSize();

    if (!WorldBounds.IsValid) return FReply::Unhandled();

    
    const float NormalizedX = LocalClick.X / MapSize.X;
    const float NormalizedY = LocalClick.Y / MapSize.Y;

    const float WorldX = FMath::Lerp(WorldBounds.Min.X, WorldBounds.Max.X, NormalizedX);
    const float WorldY = FMath::Lerp(WorldBounds.Min.Y, WorldBounds.Max.Y, 1.0f - NormalizedY);

    
    LastClickMapPos = FVector2D(LocalClick.X, LocalClick.Y);
    bHasLine = true;

    return FReply::Handled();
}

void UMapWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    if (APawn* P = UGameplayStatics::GetPlayerPawn(this, 0))
    {
        FVector2D MapSize = MyGeometry.GetLocalSize();
        CharacterMapPos = WorldToMap(P->GetActorLocation(), MapSize);

        if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(CharacterIcon->Slot))
        {
            CanvasSlot->SetPosition(CharacterMapPos);
            CanvasSlot->SetAlignment(FVector2D(0.5f, 0.5f));
        }
        CharacterIcon->SetRenderTransformAngle(P->GetActorRotation().Yaw);
    }

}


FBox UMapWidget::CalculateLevelBounds(UWorld* World) const
{
 
    FBox LevelBounds(EForceInit::ForceInit);

   
    for (TActorIterator<AActor> It(World); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor) continue;

       
        const FBox ActorBox = Actor->GetComponentsBoundingBox(/*bNonColliding=*/ true);

        
        if (ActorBox.GetExtent() != FVector::ZeroVector || ActorBox.GetCenter() != FVector::ZeroVector)
        {
            LevelBounds += ActorBox;
        }
    }

    return LevelBounds;
}


FVector2D UMapWidget::WorldToMap(const FVector& WorldLocation, const FVector2D& MapSize) const
{
    if (!WorldBounds.IsValid || MapSize.X <= 0 || MapSize.Y <= 0)
        return FVector2D::ZeroVector;

   
    const float NormalizedX = (WorldLocation.X - WorldBounds.Min.X) / (WorldBounds.Max.X - WorldBounds.Min.X);
    const float NormalizedY = (WorldLocation.Y - WorldBounds.Min.Y) / (WorldBounds.Max.Y - WorldBounds.Min.Y);

    
    FVector2D MapPos;
    MapPos.X = NormalizedX * MapSize.X;
    MapPos.Y = (1.0f - NormalizedY) * MapSize.Y;

    return MapPos;
}

int32 UMapWidget::NativePaint(
    const FPaintArgs& Args,
    const FGeometry& AllottedGeometry,
    const FSlateRect& MyCullingRect,
    FSlateWindowElementList& OutDrawElements,
    int32 LayerId,
    const FWidgetStyle& InWidgetStyle,
    bool bParentEnabled) const
{
    int32 CurrentLayer = LayerId;

    if (bHasLine)
    {
        FSlateDrawElement::MakeLines(
            OutDrawElements,
            CurrentLayer,
            AllottedGeometry.ToPaintGeometry(),
            { CharacterMapPos, LastClickMapPos },
            ESlateDrawEffect::None,
            FLinearColor::Green,
            true,
            2.0f 
        );
    }

    return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, CurrentLayer + 1, InWidgetStyle, bParentEnabled);
}
