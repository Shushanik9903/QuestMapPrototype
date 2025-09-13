// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FullMapUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUESTMAPPROTOTYPE_API UFullMapUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
    UPROPERTY(meta = (BindWidget))
    class UImage* MapImage;

    UPROPERTY(meta = (BindWidget))
    class UImage* CharacterIcon;

    FVector2D LastClickMapPos;
    FVector2D CharacterMapPos;
    bool bHasLine = false;

    virtual int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled) const override;
private:

    FBox WorldBounds;

    FBox CalculateLevelBounds(UWorld* World) const;

    
    FVector2D WorldToMap(const FVector& WorldLocation, const FVector2D& MapSize) const;
};
