// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGCurrentWeapon.h"
#include "RPGCurrentWeaponComponent.generated.h"

class IRPGInventory;

UCLASS()
class ACTIONRPG_API URPGCurrentWeaponComponent : public URPGBaseComponent, public IRPGCurrentWeapon
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void SetCurrentWeapon(const FName& InWeapon) override;
    virtual const FName& GetCurrentWeapon() const override;
	virtual FOnCurrentWeaponChanged& OnCurrentWeaponChanged() override;
	virtual FOnDealDamage& OnDealDamage() override;
	void DoDamage() const;

private:
	FOnCurrentWeaponChanged OnCurrentWeaponChangedEvent;
	FOnDealDamage OnDealDamageEvent;
	FName CurrenWeapon;
	IRPGInventory* Inventory;

	void UpdateCurrentWeapon();
};
