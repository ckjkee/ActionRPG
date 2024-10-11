// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "HUD/RPGGameHudWidget.h"
#include "Utility/RPGHelperFunctions.h"
#include "UI/RPGInventoryWidget.h"
#include "UI/RPGInventoryMessagesWidget.h"
#include "UI/RPGDamageMessagesWidget.h"
#include "Interfaces/RPGInventory.h"
#include "Interfaces/RPGHUDPlayerController.h"
#include "Interfaces/RPGHealth.h"
#include "Interfaces/RPGCurrentWeapon.h"


void URPGGameHudWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if(!GetOwningPlayerPawn())
    {
        Hide();
        return;
    }
    check(InventoryWidget);
    IRPGInventory* Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(GetOwningPlayerPawn());
    check(Inventory);
    InventoryWidget->SetInventory(Inventory);
    InventoryWidget->Hide();

    check(InventoryMessagesWidget);
    InventoryMessagesWidget->SetInventory(Inventory);

    IRPGHealth* Health = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwningPlayerPawn());
    check(Health);
    IRPGCurrentWeapon* CurrentWeapon = RPGHelperFunctions::GetComponentByInterface<IRPGCurrentWeapon>(GetOwningPlayerPawn());
    check(CurrentWeapon);
    check(DamageMessagesWidget);
    DamageMessagesWidget->SetPlayerHealthComponent(Health);
    DamageMessagesWidget->SetPlayerCurrentWeaponComponent(CurrentWeapon);


    IRPGHUDPlayerController* HUDController = Cast<IRPGHUDPlayerController>(GetOwningPlayer());
    check(HUDController);
    HUDController->OnInventoryWidgetToggled().AddUObject(InventoryWidget, &ThisClass::Toggle);
}
