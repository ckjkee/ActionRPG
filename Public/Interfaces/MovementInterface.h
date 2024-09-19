// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MovementInterface.generated.h"


UINTERFACE(MinimalAPI)
class UMovementInterface : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IMovementInterface
{
	GENERATED_BODY()

public:
    virtual bool GetIsFalling() const = 0;
};
