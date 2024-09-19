// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RPGCharacter.h"
#include "RPGAnimalCharacter.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGAnimalCharacter final : public ARPGCharacter
{
    GENERATED_BODY()

public:
    ARPGAnimalCharacter();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BlockingCollision;
};
