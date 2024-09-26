// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGHealthComponent.h"
#include "Interfaces/RPGAttributes.h"
#include "Utility/RPGHelperFunctions.h"

void URPGHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentHealth(MaxHealth);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
    Attributes = RPGHelperFunctions::GetComponentByInterface<IRPGAttributes>(GetOwner());
    if (Attributes)
    {
        Attributes->OnAttributesChanged().AddUObject(this, &ThisClass::UpdateHealth);
    }
}

void URPGHealthComponent::UpdateHealth(const float NewHealth)
{
    MaxHealth = NewHealth;
    SetCurrentHealth(MaxHealth);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
}

// Delay before starting tick healing
void URPGHealthComponent::DelayBeforeRecovery()
{
    if (!DelayBeforeRecoveryTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(DelayBeforeRecoveryTimer, this, &ThisClass::StartRecovery, DelayValue, false);
    }
}

// Function for START healing per Tick
void URPGHealthComponent::StartRecovery()
{
    if (!RecoveryHealthTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(RecoveryHealthTimer, this, &ThisClass::RecoveryHealth, RecoveryRate, true);
    }
}

// Healing Per Tick
void URPGHealthComponent::RecoveryHealth()
{
    SetCurrentHealth(CurrentHealth + HealthPerTick);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
    if (FMath::IsNearlyEqual(CurrentHealth, MaxHealth))
    {
        GetWorldTimerManager().ClearTimer(DelayBeforeRecoveryTimer);
        GetWorldTimerManager().ClearTimer(RecoveryHealthTimer);
    }
}

// Function for healing with items
void URPGHealthComponent::AddHealth(const float Value)
{
    SetCurrentHealth(CurrentHealth + Value);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
}

// Managing Health in all ways and broadcasting death
void URPGHealthComponent::SetCurrentHealth(const float InCurrentHealth)
{
    if (bIsDead)
    {
        return;
    }
    CurrentHealth = FMath::Clamp(InCurrentHealth, 0, MaxHealth);
    if (FMath::IsNearlyZero(CurrentHealth))
    {
        bIsDead = true;
        OnDeadEvent.Broadcast();
    }
}

// Take Damage Function
void URPGHealthComponent::ReduceHealth(const float Value)
{
    SetCurrentHealth(CurrentHealth - Value);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
    OnDamageTakenEvent.Broadcast();
    if (DelayBeforeRecoveryTimer.IsValid())
    {
        GetWorldTimerManager().ClearTimer(DelayBeforeRecoveryTimer);
        GetWorldTimerManager().ClearTimer(RecoveryHealthTimer);
    }
    DelayBeforeRecovery();
}

FOnDead& URPGHealthComponent::OnDead()
{
    return OnDeadEvent;
}

FOnHealthChanged& URPGHealthComponent::OnHealthChanged()
{
    return OnHealthChangedEvent;
}

FOnDamageTaken& URPGHealthComponent::OnDamageTaken()
{
    return OnDamageTakenEvent;
}

void URPGHealthComponent::ResetCharacterForResurrect()
{
    bIsDead = false;
    SetCurrentHealth(MaxHealth);
    OnHealthChangedEvent.Broadcast(CurrentHealth);
}
