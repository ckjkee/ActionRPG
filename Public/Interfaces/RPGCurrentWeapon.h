// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGCurrentWeapon.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnCurrentWeaponChanged, FName& /*NewWeapon*/)

    UINTERFACE(MinimalAPI) class URPGCurrentWeapon : public UInterface
{
    GENERATED_BODY()
};

class ACTIONRPG_API IRPGCurrentWeapon
{
    GENERATED_BODY()

public:
    virtual void SetCurrentWeapon(const FName& InWeapon) = 0;
    virtual const FName& GetCurrentWeapon() const = 0;
    virtual FOnCurrentWeaponChanged& OnCurrentWeaponChanged() = 0;
};
