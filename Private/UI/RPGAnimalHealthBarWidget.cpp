// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGAnimalHealthBarWidget.h"
#include "Components/ProgressBar.h"


void URPGAnimalHealthBarWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
}

void URPGAnimalHealthBarWidget::UpdateProgressBar(const float CurrentHealth, const float MaxHealth)
{
     if(HealthBar)
    {
        HealthBar->SetPercent(CurrentHealth / MaxHealth);
    }
}
