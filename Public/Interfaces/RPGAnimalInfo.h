// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGAnimalInfo.generated.h"

UINTERFACE(MinimalAPI)
class URPGAnimalInfo : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGAnimalInfo
{
	GENERATED_BODY()

public:
	virtual void SetMovementSpeed(const float Value) = 0;
};
