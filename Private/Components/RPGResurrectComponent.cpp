// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGResurrectComponent.h"
#include "Utility/RPGHelperFunctions.h"
#include "Interfaces/RPGHealth.h"

void URPGResurrectComponent::BeginPlay()
{
    Super::BeginPlay();
    HealthComponent = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwner());
    check(HealthComponent);
    HealthComponent->OnDead().AddUObject(this, &ThisClass::StartResurrection);
}

FOnRespawnPlayer& URPGResurrectComponent::OnRespawnPlayer()
{    
    return OnRespawnPlayerEvent;
}

void URPGResurrectComponent::StartResurrection()
{
    PlayerToResurrect = GetOwner();
    check(PlayerToResurrect);
    if (!ResurrectionTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(ResurrectionTimer, this, &ThisClass::Resurrect, TimeToResurrect, false);
    }
}

void URPGResurrectComponent::Resurrect()
{
    check(PlayerToResurrect);
    PlayerToResurrect->SetActorLocation(ResurrectLocation);
    HealthComponent->ResetCharacterForResurrect();
    OnRespawnPlayerEvent.Broadcast();
    GetWorldTimerManager().ClearTimer(ResurrectionTimer);
}

