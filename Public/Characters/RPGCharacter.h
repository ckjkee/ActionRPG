// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/MovementInterface.h"
#include "RPGCharacter.generated.h"

class URPGHealthComponent;
class URPGAttributesComponent;
class URPGExperienceComponent;
class URPGInventoryComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGCharacter : public ACharacter, public IMovementInterface
{
    GENERATED_BODY()

public:
    ARPGCharacter();

    virtual bool GetIsFalling() const override;


protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URPGHealthComponent* HealthComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URPGAttributesComponent* AttributesComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URPGExperienceComponent* ExperienceComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    URPGInventoryComponent* InventoryComponent;
};
