// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGInteractComponent.h"

void URPGInteractComponent::Start(USceneComponent* InSceneComponent)
{
    SceneComponent = InSceneComponent;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::InteractTick, TimerTickRate, true);
}

AActor* URPGInteractComponent::GetInteractingActor() const
{
    return InteractingActor;
}

void URPGInteractComponent::InteractTick()
{
    check(SceneComponent);
    FVector Location;
    FRotator Rotation;
    GetOwner()->GetInstigatorController()->GetPlayerViewPoint(Location, Rotation);
    const FVector StartLocation = SceneComponent->GetComponentLocation();
    const FVector EndLocation = StartLocation + Rotation.Vector() * Distance;

    FHitResult OutHit;
    UKismetSystemLibrary::SphereTraceSingle(this, StartLocation, EndLocation, Radius, TraceTypeQuery, false, TArray<AActor*>(), DebugType, OutHit,
                                            true);
    if (OutHit.GetActor() != InteractingActor)
    {
        OnLeftEvent.Broadcast(InteractingActor);
        InteractingActor = OutHit.GetActor();
        OnEnteredEvent.Broadcast(InteractingActor);
    }
}
