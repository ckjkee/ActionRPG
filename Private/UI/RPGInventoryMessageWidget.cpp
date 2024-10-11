// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGInventoryMessageWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void URPGInventoryMessageWidget::NativeConstruct()
{
    Super::NativeConstruct();
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::RemoveFromParent, DelayBeforeRemove);
}

void URPGInventoryMessageWidget::SetItemName(const FText& InItemName) const
{
    check(ItemNameTextBlock);
    ItemNameTextBlock->SetText(InItemName);
}

void URPGInventoryMessageWidget::SetItemCount(const int32 InItemCount) const
{
    check(ItemCountTextBlock);
    ItemCountTextBlock->SetText(FText::AsNumber(FMath::Abs(InItemCount)));
    SetType(InItemCount > 0);
}

void URPGInventoryMessageWidget::SetItemTotal(const uint32 InItemTotal) const
{
    check(ItemTotalTextBlock);
    ItemTotalTextBlock->SetText(FText::AsNumber(InItemTotal));
}

void URPGInventoryMessageWidget::SetType(const bool bIsAdded) const
{
    check(PlusImage);
    check(MinusImage);
    if (bIsAdded)
    {
        PlusImage->SetVisibility(ESlateVisibility::Visible);
        MinusImage->SetVisibility(ESlateVisibility::Collapsed);
    }
    else
    {
        PlusImage->SetVisibility(ESlateVisibility::Visible);
        MinusImage->SetVisibility(ESlateVisibility::Collapsed);
    }
}
