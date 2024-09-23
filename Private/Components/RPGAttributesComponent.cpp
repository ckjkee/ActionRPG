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

void URPGAttributesComponent::SetNewAttributes(int16 CharacterLevel)
{
    CurrentHealth = BaseHealth * FMath::Pow(1.1, CharacterLevel);
    OnAttributesChangedEvent.Broadcast(CurrentHealth);
    CurrentDamage = BaseDamage * FMath::Pow(1.1, CharacterLevel);
    CurrentAttackSpeed = BaseAttackSpeed * FMath::Pow(1.1, CharacterLevel);
    UE_LOG(LogTemp, Warning, TEXT("Health = %f"), CurrentHealth);
    UE_LOG(LogTemp, Warning, TEXT("Damage = %f"), CurrentDamage);
    UE_LOG(LogTemp, Warning, TEXT("AttackSpeed = %f"), CurrentAttackSpeed);
}

FOnAttributesChanged& URPGAttributesComponent::OnAttributesChanged()
{
    return OnAttributesChangedEvent;
}
