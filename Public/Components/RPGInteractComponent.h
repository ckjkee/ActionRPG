// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interfaces/RPGFocus.h"
#include "RPGInteractComponent.generated.h"

UCLASS()
class ACTIONRPG_API URPGInteractComponent : public URPGBaseComponent, public IRPGFocus
{
    GENERATED_BODY()

public:
    FOnEntered OnEnteredEvent;
    FOnLeft OnLeftEvent;
    void Start(USceneComponent* InSceneComponent);
    AActor* GetInteractingActor() const;

    virtual FOnEntered& OnEnter() override;
    virtual FOnLeft& OnLeft() override;

private:
    FTimerHandle TimerHandle;

    UPROPERTY()
    USceneComponent* SceneComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float TimerTickRate = 0.1f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
    float Radius = 40.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
    float Distance = 100.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TEnumAsByte<ETraceTypeQuery> TraceTypeQuery;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TEnumAsByte<EDrawDebugTrace::Type> DebugType;

    UPROPERTY()
    AActor* InteractingActor;

    void InteractTick();
};
