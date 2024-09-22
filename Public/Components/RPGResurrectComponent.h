// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "RPGResurrectComponent.generated.h"

class IRPGHealth;

UCLASS()
class ACTIONRPG_API URPGResurrectComponent final : public URPGBaseComponent
{
    GENERATED_BODY()
public:
    virtual void BeginPlay() override;

    void SetHealthComponent(IRPGHealth* InHealthComponent);

    UFUNCTION(BlueprintCallable)
    void StartResurrection();

    void Resurrect();

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FVector ResurrectLocation = FVector::ZeroVector;

    FTimerHandle ResurrectionTimer;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float TimeToResurrect = 5.f;

    AActor* PlayerToResurrect;

    IRPGHealth* HealthComponent;
};
