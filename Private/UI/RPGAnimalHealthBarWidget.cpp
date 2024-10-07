// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGAnimalHealthBarWidget.h"
#include "Components/ProgressBar.h"
#include "Interfaces/RPGInteract.h"
#include "Interfaces/RPGHealth.h"
#include "Interfaces/RPGFocus.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "Utility/RPGHelperFunctions.h"

void URPGAnimalHealthBarWidget::NativePreConstruct()
{
    SetVisibility(ESlateVisibility::Hidden);
    Super::NativePreConstruct();
    HealthComponent = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwningPlayerPawn());
    if (HealthComponent)
    {
        if (HealthBar)
        {
            UpdateWidget(HealthComponent->GetCurrentHealth());
        }
        HealthComponent->OnHealthChanged().AddUObject(this, &ThisClass::UpdateWidget);
    }
    InteractComponent = RPGHelperFunctions::GetComponentByInterface<IRPGFocus>(GetOwningPlayerPawn());
    if (InteractComponent)
    {
        InteractComponent->OnEnter().AddUObject(this, &ThisClass::IsInFocus);
        InteractComponent->OnLeft().AddUObject(this, &ThisClass::IsOutOfFocus);
    }
}

void URPGAnimalHealthBarWidget::IsInFocus(AActor* Actor)
{
    if (!IsVisible() && Cast<IRPGAnimalInfo>(Actor))
    {
        SetVisibility(ESlateVisibility::Visible);
    }
}

void URPGAnimalHealthBarWidget::IsOutOfFocus(AActor* Actor)
{
    if (IsVisible())
    {
        SetVisibility(ESlateVisibility::Hidden);
    }
}

void URPGAnimalHealthBarWidget::UpdateWidget(const float InHealth)
{
    check(HealthBar);
    HealthBar->SetPercent(HealthComponent->GetCurrentHealth() / HealthComponent->GetMaxHealth());
}
