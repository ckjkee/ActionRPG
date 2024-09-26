// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RPGCharacter.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "RPGAnimalCharacter.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGAnimalCharacter final : public ARPGCharacter, public IRPGAnimalInfo
{
    GENERATED_BODY()

public:
    ARPGAnimalCharacter();

    virtual void SetMovementSpeed(const float Value) override;
    virtual void SetLevelForSpawn(uint16 InLevel) override;

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BlockingCollision;
};
