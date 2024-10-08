// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGComponents.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnReachNewLevel, int16) DECLARE_MULTICAST_DELEGATE(FOnExperienceChange)

    UINTERFACE(MinimalAPI) class URPGComponents : public UInterface
{
    GENERATED_BODY()
};

class ACTIONRPG_API IRPGComponents
{
    GENERATED_BODY()

public:
    virtual FOnReachNewLevel& OnReachNewLevel() = 0;
    virtual FOnExperienceChange& OnExperienceChange() = 0;
    virtual uint16 GetCurrentLevel() = 0;
    virtual int32 GetCurrentTreshold() const = 0;
    virtual int32 GetCurrentCharacterExperience() const = 0;
};
