// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "HUD/RPGGameHudWidget.h"
#include "UI/RPGCurrentWeaponWidget.h"
#include "Interfaces/RPGCurrentWeapon.h"
#include "Utility/RPGHelperFunctions.h"
#include "UI/RPGInventoryWidget.h"
#include "Interfaces/RPGInventory.h"

void URPGGameHudWidget::NativeConstruct()
{
    Super::NativeConstruct();
    check(InventoryWidget);
    IRPGInventory* Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(GetOwningPlayerPawn());
    check(Inventory);
    InventoryWidget->SetInventory(Inventory);
    IRPGCurrentWeapon* Curr = RPGHelperFunctions::GetComponentByInterface<IRPGCurrentWeapon>(GetOwningPlayerPawn());
    Curr->SetCurrentWeapon(Inventory->GetFirstWeapon());
}
