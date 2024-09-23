// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGCameraShakeSourceComponent.h"
#include "Interfaces/RPGHealth.h"
#include "Utility/RPGHelperFunctions.h"

void URPGCameraShakeSourceComponent::BeginPlay()
{
    Super::BeginPlay();
    HealthComponent = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwner());
    check(HealthComponent);
    HealthComponent->OnDamageTaken().AddUObject(this, &ThisClass::StartShaking);
}

void URPGCameraShakeSourceComponent::StartShaking() 
{
    StartCameraShake(CameraShake, Scale);
}

void URPGCameraShakeSourceComponent::StopShaking() 
{
    StopAllCameraShakes();
}