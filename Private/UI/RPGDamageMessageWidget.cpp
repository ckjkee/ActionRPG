// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGDamageMessageWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void URPGDamageMessageWidget::NativeConstruct()
{
    Super::NativeConstruct();
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::RemoveFromParent, DelayBeforeRemove);
}

void URPGDamageMessageWidget::SetDamageTakenNumbers(const float InNumbers) const
{
    check(DamageTakenNumbersTextBlock);
    DamageTakenNumbersTextBlock->SetText(FText::AsNumber(InNumbers));
    SetType(InNumbers < 0);
}

void URPGDamageMessageWidget::SetDamageDealtNumbers(const float InNumbers) const
{
    check(DamageDealtNumbersTextBlock);
    DamageDealtNumbersTextBlock->SetText(FText::AsNumber(InNumbers));
    SetType(InNumbers < 0);
}

void URPGDamageMessageWidget::SetType(const bool bIsDamageTaken) const
{
    if (bIsDamageTaken)
    {
        DamageTakenNumbersTextBlock->SetVisibility(ESlateVisibility::Visible);
        DamageDealtNumbersTextBlock->SetVisibility(ESlateVisibility::Collapsed);
    }
    else
    {
        DamageTakenNumbersTextBlock->SetVisibility(ESlateVisibility::Collapsed);
        DamageDealtNumbersTextBlock->SetVisibility(ESlateVisibility::Visible);
    }
}
