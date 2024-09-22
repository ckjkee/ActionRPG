// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGResurrectComponent.h"
#include "Characters/RPGPlayerCharacter.h"
#include "Interfaces/RPGHealth.h"

void URPGResurrectComponent::BeginPlay()
{
    Super::BeginPlay();
    HealthComponent->OnDead().AddUObject(this, &ThisClass::StartResurrection);
}

void URPGResurrectComponent::StartResurrection()
{
    PlayerToResurrect = GetOwner();
    if (!ResurrectionTimer.IsValid())
    {
        GetWorldTimerManager().SetTimer(ResurrectionTimer, this, &ThisClass::Resurrect, TimeToResurrect, false);
    }
}

void URPGResurrectComponent::Resurrect()
{
    PlayerToResurrect->SetActorLocation(ResurrectLocation);
    GetWorldTimerManager().ClearTimer(ResurrectionTimer);
    UE_LOG(LogTemp, Warning, TEXT("Player = %s"), *PlayerToResurrect->GetName());
}

void URPGResurrectComponent::SetHealthComponent(IRPGHealth* InHealthComponent)
{
    check(InHealthComponent);
    HealthComponent = InHealthComponent;
}
