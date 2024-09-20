// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGBaseComponent.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API URPGBaseComponent : public UActorComponent
{
    GENERATED_BODY()

    protected:
    FTimerManager& GetWorldTimerManager() const;
};
