// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGHealthWidget.h"
#include "Components/ProgressBar.h"
#include "Interfaces/RPGHealth.h"
#include "Utility/RPGHelperFunctions.h"

void URPGHealthWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
    HealthComponent = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwningPlayerPawn());
    if (HealthComponent)
    {
        HealthComponent->OnHealthChanged().AddUObject(this, &ThisClass::UpdateWidget);
        if (HealthBar)
        {
            UpdateWidget(HealthComponent->GetCurrentHealth());
        }
    }
}

void URPGHealthWidget::UpdateWidget(const float InHealth)
{
    check(HealthBar);
    HealthBar->SetPercent(InHealth/HealthComponent->GetMaxHealth());
}
