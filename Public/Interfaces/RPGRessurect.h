// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGRessurect.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnRespawnPlayer)

UINTERFACE(MinimalAPI)
class URPGRessurect : public UInterface
{
    GENERATED_BODY()
};

class ACTIONRPG_API IRPGRessurect
{
    GENERATED_BODY()

public:
    virtual FOnRespawnPlayer& OnRespawnPlayer() = 0;
};
