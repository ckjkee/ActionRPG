// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGHealthComponent.h"

void URPGHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
}

void URPGHealthComponent::DelayBeforeRecovery()
{
    if (!DelayBeforeRecoveryTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(DelayBeforeRecoveryTimer, this, &ThisClass::StartRecovery, DelayValue, false);
    }
}

void URPGHealthComponent::StartRecovery()
{
    if (!RecoveryHealthTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(RecoveryHealthTimer, this, &ThisClass::RecoveryHealth, RecoveryRate, true);
    }
}

void URPGHealthComponent::RecoveryHealth()
{
    SetCurrentHealth(CurrentHealth + HealthPerTick);
    if (FMath::IsNearlyEqual(CurrentHealth, MaxHealth))
    {
        GetWorldTimerManager().ClearTimer(DelayBeforeRecoveryTimer);
        GetWorldTimerManager().ClearTimer(RecoveryHealthTimer);
    }
}

void URPGHealthComponent::AddHealth(const float Value)
{
    SetCurrentHealth(CurrentHealth + Value);
}

void URPGHealthComponent::ReduceHealth(const float Value)
{
    SetCurrentHealth(CurrentHealth - Value);
    if (DelayBeforeRecoveryTimer.IsValid())
    {
        GetWorldTimerManager().ClearTimer(DelayBeforeRecoveryTimer);
        GetWorldTimerManager().ClearTimer(RecoveryHealthTimer);
    }
    DelayBeforeRecovery();
}

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
