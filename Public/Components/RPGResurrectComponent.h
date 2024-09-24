// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGRessurect.h"
#include "RPGResurrectComponent.generated.h"

class IRPGHealth;

UCLASS()
class ACTIONRPG_API URPGResurrectComponent final : public URPGBaseComponent, public IRPGRessurect
{
    GENERATED_BODY()
public:
    virtual FOnRespawnPlayer& OnRespawnPlayer() override;

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void StartResurrection();

    void Resurrect();

    FOnRespawnPlayer OnRespawnPlayerEvent;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FVector ResurrectLocation = FVector::ZeroVector;

    FTimerHandle ResurrectionTimer;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float TimeToResurrect = 5.f;

    AActor* PlayerToResurrect;

    IRPGHealth* HealthComponent;
};
