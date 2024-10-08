// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGInventorySlotWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Bases/CoreTypes/RPGTypes.h"
#include "Utility/RPGItemHelper.h"

void URPGInventorySlotWidget::NativeConstruct()
{
    Super::NativeConstruct();
    SlotButton->OnClicked.AddDynamic(this, &ThisClass::OnSlotClicked);
}

void URPGInventorySlotWidget::OnSlotClicked()
{
    OnInventorySlotButtonClickedEvent.Broadcast(ItemSlot.RowName);
}

void URPGInventorySlotWidget::SetItem(const FRPGItemSlot& InItemSlot)
{
    check(Thumbnail);
    check(ItemName);

    ItemSlot = InItemSlot;
    const FRPGItemInfo* ItemInfo = FRPGItemHelper::GetItemInfo(ItemSlot.RowName);
    Thumbnail->SetBrushFromTexture(ItemInfo->Thumbnail);
    ItemName->SetText(MakeValidName(ItemInfo->Name));
}

FText URPGInventorySlotWidget::MakeValidName(const FText& InName) const
{
    return FText::Format(FTextFormat::FromString("{0} x {1}"), InName, ItemSlot.Count);
}

bool URPGInventorySlotWidget::IsActive() const
{
    return ItemSlot.bIsActive;
}