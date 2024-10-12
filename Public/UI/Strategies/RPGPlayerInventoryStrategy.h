// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Strategies/RPGInventoryStrategy.h"
#include "RPGPlayerInventoryStrategy.generated.h"


UCLASS(Abstract, Blueprintable)
class ACTIONRPG_API URPGPlayerInventoryStrategy final : public URPGInventoryStrategy
{
	GENERATED_BODY()
public:
	virtual void OnClicked(const FName& InRowName) const override;
};
