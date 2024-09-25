// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGAttributesComponent.h"
#include "Utility/RPGHelperFunctions.h"
#include "Interfaces/RPGComponents.h"


void URPGAttributesComponent::BeginPlay()
{
    Super::BeginPlay();
    ExperienceComponent = RPGHelperFunctions::GetComponentByInterface<IRPGComponents>(GetOwner());
    SetNewAttributes(ExperienceComponent->GetCurrentLevel()); // TODO DELETE
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
    UE_LOG(LogTemp, Warning, TEXT("Health = %f"), CurrentHealth);           // TODO DElETE
    UE_LOG(LogTemp, Warning, TEXT("Damage = %f"), CurrentDamage);           // TODO DELETE
    UE_LOG(LogTemp, Warning, TEXT("AttackSpeed = %f"), CurrentAttackSpeed); // TODO DELETE
}

FOnAttributesChanged& URPGAttributesComponent::OnAttributesChanged()
{
    return OnAttributesChangedEvent;
}

float URPGAttributesComponent::GetAttackSpeed() const
{
    return CurrentAttackSpeed;
}

float URPGAttributesComponent::GetCurrentDamage() const
{
    return CurrentDamage;
}
