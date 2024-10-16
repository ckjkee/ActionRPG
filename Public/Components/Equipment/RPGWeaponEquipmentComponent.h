// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Equipment/RPGEquipmentComponent.h"
#include "RPGWeaponEquipmentComponent.generated.h"


UCLASS(Abstract)
class ACTIONRPG_API URPGWeaponEquipmentComponent : public URPGEquipmentComponent
{
	GENERATED_BODY()
public:
	void ToggleCombatMode();
	bool IsInCombatMode() const;
	void SetCombatEquipSocket(USceneComponent* InCombatEquipSocket);

protected:
	virtual void UnEquip() override;

private:
	bool bIsCombatMode;

	UPROPERTY()
	USceneComponent* CombatEquipSocket;

	void StartCombatMode();
	void StopCombatMode();
};
