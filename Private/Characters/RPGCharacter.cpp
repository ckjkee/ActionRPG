// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/RPGHealthComponent.h"

ARPGCharacter::ARPGCharacter() : Super()
{
    HealthComponent = CreateDefaultSubobject<URPGHealthComponent>(TEXT("HealthComponent"));
    check(HealthComponent);
}

bool ARPGCharacter::GetIsFalling() const
{
    check(GetMovementComponent());
    return GetMovementComponent()->IsFalling();
    
}
