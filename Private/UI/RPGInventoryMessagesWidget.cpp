// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGInventoryMessagesWidget.h"
#include "UI/RPGInventoryMessageWidget.h"
#include "Components/PanelWidget.h"
#include "Utility/RPGItemHelper.h"
#include "Interfaces/RPGInventory.h"


void URPGInventoryMessagesWidget::OnAddItem(const FName& InName, const uint32 InCount)
{
    CreateInventoryMessageWidget(InName, InCount);
}

void URPGInventoryMessagesWidget::OnRemoveItem(const FName& InName, const uint32 InCount)
{
    CreateInventoryMessageWidget(InName, -1 * InCount);
}

void URPGInventoryMessagesWidget::CreateInventoryMessageWidget(const FName& InName, const int InCount)
{
    check(MessageWidgetClass);
    check(PanelWidget);
    check(Inventory);

    URPGInventoryMessageWidget* MessageWidget = CreateWidget<URPGInventoryMessageWidget>(this, MessageWidgetClass);
    check(MessageWidget);
    MessageWidget->SetItemName(FRPGItemHelper::GetItemName(InName));
    MessageWidget->SetItemCount(InCount);
    MessageWidget->SetItemTotal(Inventory->GetItemCount(InName));

    PanelWidget->AddChild(MessageWidget);
}

void URPGInventoryMessagesWidget::SetInventory(IRPGInventory* InInventory)
{
    check(InInventory);
    Inventory = InInventory;
    Inventory->OnAddedItem().AddUObject(this, &ThisClass::OnAddItem);
    Inventory->OnRemovedItem().AddUObject(this, &ThisClass::OnRemoveItem);
}
