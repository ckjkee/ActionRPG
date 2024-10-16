// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGEquipment.generated.h"

UINTERFACE(MinimalAPI)
class URPGEquipment : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGEquipment
{
	GENERATED_BODY()

public:
	virtual void ToggleEquip(const FName& RowName) = 0;
	virtual FName GetEquippedItemRowName() const = 0;
};
