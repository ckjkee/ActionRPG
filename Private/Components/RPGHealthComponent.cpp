// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGHealthComponent.h"

void URPGHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    SetCurrentHealth(MaxHealth);
    OnHealthChanged.Broadcast(CurrentHealth);
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
    OnHealthChanged.Broadcast(CurrentHealth);
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
    OnHealthChanged.Broadcast(CurrentHealth);
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
        OnDead.Broadcast();
    }
}

// Take Damage Function
void URPGHealthComponent::ReduceHealth(const float Value)
{
    SetCurrentHealth(CurrentHealth - Value);
    OnHealthChanged.Broadcast(CurrentHealth);
    if (DelayBeforeRecoveryTimer.IsValid())
    {
        GetWorldTimerManager().ClearTimer(DelayBeforeRecoveryTimer);
        GetWorldTimerManager().ClearTimer(RecoveryHealthTimer);
    }
    DelayBeforeRecovery();
}
