// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGCameraShake.generated.h"

UINTERFACE(MinimalAPI)
class URPGCameraShake : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGCameraShake
{
	GENERATED_BODY()

public:
    virtual void StartShaking() = 0;
    virtual void StopShaking() = 0;
};
