// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGHealthWidgetComponent.h"
#include "Interfaces/RPGHealth.h"
#include "Interfaces/RPGFocus.h"
#include "Utility/RPGHelperFunctions.h"

URPGHealthWidgetComponent::URPGHealthWidgetComponent()
{
    SetWidgetSpace(EWidgetSpace::Screen);
    SetDrawAtDesiredSize(true);
    SetVisibility(false);

    Health = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwner());
    if (Health)
    {
        Health->OnHealthChanged().AddUObject(this, &ThisClass::UpdateProgressBar);
    }
}

void URPGHealthWidgetComponent::BeginPlay()
{
    Super::BeginPlay();
    UpdateProgressBar(Health->GetCurrentHealth());
}

void URPGHealthWidgetComponent::UpdateProgressBar(const float InCurrentHealth)
{
    IRPGFocus* HealthBar = Cast<IRPGFocus>(GetWidget());
    if (HealthBar)
    {
        HealthBar->UpdateProgressBar(InCurrentHealth, Health->GetMaxHealth());
    }
}
