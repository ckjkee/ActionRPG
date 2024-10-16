// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Components/Equipment/RPGWeaponEquipmentComponent.h"

void URPGWeaponEquipmentComponent::ToggleCombatMode()
{
    if(IsEquipped())
    {
        bIsCombatMode ? StopCombatMode() : StartCombatMode();
    }
}

bool URPGWeaponEquipmentComponent::IsInCombatMode() const
{
    return bIsCombatMode;
}

void URPGWeaponEquipmentComponent::SetCombatEquipSocket(USceneComponent* InCombatEquipSocket)
{
    CombatEquipSocket = InCombatEquipSocket;
}

void URPGWeaponEquipmentComponent::UnEquip()
{
    Super::UnEquip();
    StopCombatMode();
}

void URPGWeaponEquipmentComponent::StartCombatMode()
{
    bIsCombatMode = true;
    AttachActorToSocket(CombatEquipSocket);
}

void URPGWeaponEquipmentComponent::StopCombatMode()
{
    bIsCombatMode = false;
    AttachActorToSocket();
}
