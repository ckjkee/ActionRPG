// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Components/RPGCurrentWeaponComponent.h"
#include "Interfaces/RPGInventory.h"
#include "Utility/RPGHelperFunctions.h"

void URPGCurrentWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(GetOwner());
	Inventory->OnInventoryChanged().AddUObject(this, &ThisClass::UpdateCurrentWeapon);
}

void URPGCurrentWeaponComponent::SetCurrentWeapon(const FName& InWeapon)
{
	CurrenWeapon = InWeapon;
	OnCurrentWeaponChangedEvent.Broadcast(CurrenWeapon);
}

const FName& URPGCurrentWeaponComponent::GetCurrentWeapon() const
{
    return CurrenWeapon;
}

FOnCurrentWeaponChanged& URPGCurrentWeaponComponent::OnCurrentWeaponChanged()
{
	return OnCurrentWeaponChangedEvent;
}

void URPGCurrentWeaponComponent::UpdateCurrentWeapon()
{
	SetCurrentWeapon(Inventory->GetFirstWeapon());
}
