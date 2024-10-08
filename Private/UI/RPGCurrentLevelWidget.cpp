// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGCurrentLevelWidget.h"
#include "Interfaces/RPGComponents.h"
#include "Utility/RPGHelperFunctions.h"
#include "Components/TextBlock.h"

void URPGCurrentLevelWidget::NativeConstruct()
{
    Super::NativeConstruct();
    IRPGComponents* ExperienceComponent = RPGHelperFunctions::GetComponentByInterface<IRPGComponents>(GetOwningPlayerPawn());
    if (ExperienceComponent)
    {
        ExperienceComponent->OnReachNewLevel().AddUObject(this, &ThisClass::UpdateCurrentLevel);
    }
}

void URPGCurrentLevelWidget::UpdateCurrentLevel(const int16 InCurrentLevel) const
{
    CurrentLevelTextBlock->SetText(FText::Format(FTextFormat::FromString("{0}"), InCurrentLevel));
}
