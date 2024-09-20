// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGAttributesComponent.h"
#include "Components/RPGExperienceComponent.h"
#include "Interfaces/RPGComponents.h"

void URPGAttributesComponent::BeginPlay()
{
    Super::BeginPlay();
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

void URPGAttributesComponent::SetExperienceComponent(IRPGComponents* InComponent)
{
    ExperienceComponent = InComponent;
}

FOnAttributesChanged& URPGAttributesComponent::OnAttributesChanged()
{
    return OnAttributesChangedEvent;
}
