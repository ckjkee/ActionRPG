// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/RPGAttributesComponent.h"
#include "Components/RPGHealthComponent.h"
#include "Components/RPGExperienceComponent.h"
#include "Components/RPGInventoryComponent.h"
#include "Components/RPGStartingItemsComponent.h"

ARPGCharacter::ARPGCharacter() : Super()
{
    HealthComponent = CreateDefaultSubobject<URPGHealthComponent>(TEXT("HealthComponent"));

    AttributesComponent = CreateDefaultSubobject<URPGAttributesComponent>(TEXT("AttributesComponent"));

    ExperienceComponent = CreateDefaultSubobject<URPGExperienceComponent>(TEXT("ExperienceComponent"));

    InventoryComponent = CreateDefaultSubobject<URPGInventoryComponent>(TEXT("InventoryComponent"));

    StartingItemsComponent = CreateDefaultSubobject<URPGStartingItemsComponent>(TEXT("StartingItems")); 
}

bool ARPGCharacter::GetIsFalling() const
{
    check(GetMovementComponent());
    return GetMovementComponent()->IsFalling();
}
