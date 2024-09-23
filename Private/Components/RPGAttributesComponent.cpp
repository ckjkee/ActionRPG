// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGAttributesComponent.h"
#include "Utility/RPGHelperFunctions.h"
#include "Interfaces/RPGComponents.h"

void URPGAttributesComponent::BeginPlay()
{
    Super::BeginPlay();
    ExperienceComponent = RPGHelperFunctions::GetComponentByInterface<IRPGComponents>(GetOwner());
    if (ExperienceComponent)
    {
        ExperienceComponent->OnReachNewLevel().AddUObject(this, &ThisClass::SetNewAttributes);
    }
}

void URPGAttributesComponent::SetNewAttributes(const int16 CharacterLevel)
{
    CurrentHealth = BaseHealth * FMath::Pow(LEVEL_AMPLIFIER, CharacterLevel);
    OnAttributesChangedEvent.Broadcast(CurrentHealth);
    CurrentDamage = BaseDamage * FMath::Pow(LEVEL_AMPLIFIER, CharacterLevel);
    CurrentAttackSpeed = BaseAttackSpeed * FMath::Pow(LEVEL_AMPLIFIER, CharacterLevel);
    UE_LOG(LogTemp, Warning, TEXT("Health = %f"), CurrentHealth);
    UE_LOG(LogTemp, Warning, TEXT("Damage = %f"), CurrentDamage);
    UE_LOG(LogTemp, Warning, TEXT("AttackSpeed = %f"), CurrentAttackSpeed);
}

FOnAttributesChanged& URPGAttributesComponent::OnAttributesChanged()
{
    return OnAttributesChangedEvent;
}
