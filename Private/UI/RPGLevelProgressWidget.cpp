// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGLevelProgressWidget.h"
#include "Interfaces/RPGComponents.h"
#include "Utility/RPGHelperFunctions.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetMathLibrary.h"

void URPGLevelProgressWidget::NativeConstruct()
{
    Super::NativeConstruct();
    ExpComponent = RPGHelperFunctions::GetComponentByInterface<IRPGComponents>(GetOwningPlayerPawn());
    check(ExpComponent);
    SetWidgetProperties();
    ExpComponent->OnExperienceChange().AddUObject(this, &ThisClass::UpdateExperienceBarAndText);
}

void URPGLevelProgressWidget::UpdateExperienceBarAndText()
{
    SetWidgetProperties();
}

void URPGLevelProgressWidget::SetWidgetProperties()
{
    check(CurrentExperienceBar);
    CurrentExperienceBar->SetPercent(float(ExpComponent->GetCurrentCharacterExperience()) / float(ExpComponent->GetCurrentTreshold()));

    check(CurrentExperienceTextBlock);
    CurrentExperienceTextBlock->SetText(MakeFormatText());
}

FText URPGLevelProgressWidget::MakeFormatText() const
{
    return FText::Format(FTextFormat::FromString("{0}/{1}"), ExpComponent->GetCurrentCharacterExperience(), ExpComponent->GetCurrentTreshold());
}
