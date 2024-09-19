// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

bool ARPGCharacter::GetIsFalling() const
{
    check(GetMovementComponent());
    return GetMovementComponent()->IsFalling();
}
