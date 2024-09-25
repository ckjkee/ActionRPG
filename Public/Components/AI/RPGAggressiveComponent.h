// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/AI/RPGAIComponent.h"
#include "RPGAggressiveComponent.generated.h"



UCLASS()
class ACTIONRPG_API URPGAggressiveComponent : public URPGAIComponent
{
    GENERATED_BODY()
public:
    virtual void Start(AAIController* InAIController) override;
    virtual void OnMoveCompleted(const bool bIsSuccess) override;
    virtual void Stop() override;
    void SetEnemy(AActor* InEnemy);

private:
    void AttackTarget();
    void MoveToTarget();

    AActor* Enemy;

    FTimerHandle TimerHandle;


    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float DelayAttackSpeed = 1.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float DelayBeforeMoves = 0.5f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
    float AcceptanceRadius = 50.f;
};
