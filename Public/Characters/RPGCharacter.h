// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/MovementInterface.h"
#include "RPGCharacter.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API ARPGCharacter : public ACharacter, public IMovementInterface
{
    GENERATED_BODY()

public:
    virtual bool GetIsFalling() const override;
};
