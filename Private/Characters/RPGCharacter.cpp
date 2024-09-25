// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/RPGAttributesComponent.h"
#include "Components/RPGHealthComponent.h"
#include "Components/RPGExperienceComponent.h"

ARPGCharacter::ARPGCharacter() : Super()
{
    HealthComponent = CreateDefaultSubobject<URPGHealthComponent>(TEXT("HealthComponent"));

    AttributesComponent = CreateDefaultSubobject<URPGAttributesComponent>(TEXT("AttributesComponent"));

    ExperienceComponent = CreateDefaultSubobject<URPGExperienceComponent>(TEXT("ExperienceComponent"));
}

bool ARPGCharacter::GetIsFalling() const
{
    check(GetMovementComponent());
    return GetMovementComponent()->IsFalling();
}
