// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Components/RPGCurrentWeaponComponent.h"
#include "Interfaces/RPGInventory.h"
#include "Utility/RPGHelperFunctions.h"
#include "Utility/RPGItemHelper.h"

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

FOnDealDamage& URPGCurrentWeaponComponent::OnDealDamage()
{
	return OnDealDamageEvent;
}

void URPGCurrentWeaponComponent::DoDamage() const
{
	OnDealDamageEvent.Broadcast(FRPGItemHelper::GetItemDamage(CurrenWeapon));
}

void URPGCurrentWeaponComponent::UpdateCurrentWeapon()
{
	SetCurrentWeapon(Inventory->GetFirstWeapon());
}
