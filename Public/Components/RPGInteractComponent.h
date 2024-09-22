// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RPGInteractComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEntered, AActor*) 
DECLARE_MULTICAST_DELEGATE_OneParam(FOnLeft, AActor*)


UCLASS()
class ACTIONRPG_API URPGInteractComponent : public URPGBaseComponent
{
    GENERATED_BODY()

public:
    FOnEntered OnEnteredEvent;
    FOnLeft OnLeftEvent;
    void Start(USceneComponent* InSceneComponent);
    inline AActor* GetInteractingActor() const;

private:
    FTimerHandle TimerHandle;

    UPROPERTY()
    USceneComponent* SceneComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
    float TimerTickRate = 0.1f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
    float Radius = 40.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
    float Distance = 200.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TEnumAsByte<ETraceTypeQuery> TraceTypeQuery;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TEnumAsByte<EDrawDebugTrace::Type> DebugType;

    UPROPERTY()
    AActor* InteractingActor;

    void InteractTick();
};
