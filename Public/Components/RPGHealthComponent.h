// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "RPGHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDead)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

UCLASS()
class ACTIONRPG_API URPGHealthComponent final : public URPGBaseComponent
{
    GENERATED_BODY()

public:
    FOnDead OnDead;

    FOnHealthChanged OnHealthChanged;

    virtual void BeginPlay() override;
    void RecoveryHealth();

    void AddHealth(const float Value);
    void ReduceHealth(const float Value);
    void SetCurrentHealth(const float InCurrentHealth);

private:
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

};
