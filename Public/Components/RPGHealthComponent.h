// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGHealth.h"
#include "RPGHealthComponent.generated.h"

class IRPGAttributes;

UCLASS()
class ACTIONRPG_API URPGHealthComponent final : public URPGBaseComponent, public IRPGHealth
{
    GENERATED_BODY()

public:
    FOnDead OnDeadEvent;

    FOnHealthChanged OnHealthChangedEvent;

    virtual inline FOnDead& OnDead() override;

    virtual void BeginPlay() override;
    void RecoveryHealth();

    void AddHealth(const float Value);
    void ReduceHealth(const float Value);
    void SetCurrentHealth(const float InCurrentHealth);
    void SetAttributes(IRPGAttributes* InAttributes);

private:
    IRPGAttributes* Attributes;

    bool bIsDead = false;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float MaxHealth = 100.f;

    float CurrentHealth = 0.f;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float HealthPerTick = 1.f;

    FTimerHandle RecoveryHealthTimer;
    FTimerHandle DelayBeforeRecoveryTimer;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float RecoveryRate = 1.f;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float DelayValue = 10.f;

    void StartRecovery();

    void DelayBeforeRecovery();

    void UpdateHealth(const float NewHealth);
};