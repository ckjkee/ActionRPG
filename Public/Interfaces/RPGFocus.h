// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGFocus.generated.h"

UINTERFACE(MinimalAPI)
class URPGFocus : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGFocus
{
	GENERATED_BODY()

public:
	virtual void UpdateProgressBar(const float CurrentHealth, const float MaxHealth) = 0;
};
