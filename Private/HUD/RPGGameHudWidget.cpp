// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "HUD/RPGGameHudWidget.h"
#include "Utility/RPGHelperFunctions.h"
#include "UI/RPGInventoryWidget.h"
#include "Interfaces/RPGInventory.h"
#include "Interfaces/RPGHUDPlayerController.h"

void URPGGameHudWidget::NativeConstruct()
{
    Super::NativeConstruct();
    check(InventoryWidget);
    IRPGInventory* Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(GetOwningPlayerPawn());
    check(Inventory);
    InventoryWidget->SetInventory(Inventory);
    InventoryWidget->Hide();
    IRPGHUDPlayerController* HUDController = Cast<IRPGHUDPlayerController>(GetOwningPlayer());
    check(HUDController);
    HUDController->OnInventoryWidgetToggled().AddUObject(InventoryWidget, &ThisClass::Toggle);
}
