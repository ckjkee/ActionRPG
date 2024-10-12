// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGBaseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/RPGGameState.h"

void URPGBaseWidget::Show()
{
    if (IsVisible())
    {
        return;
    }
    SetVisibility(ESlateVisibility::Visible);
}

void URPGBaseWidget::Hide()
{
    if(!IsVisible())
    {
        return;
    }
    if(HideAnimation)
    {
        StopAllAnimations();
        OnAnimationFinishedEvent.BindDynamic(this, &ThisClass::HideAnimationFinished);
        BindToAnimationFinished(HideAnimation, OnAnimationFinishedEvent);
        PlayAnimation(HideAnimation);
    }
    else
    {
        HideAnimationFinished();
    }
}

void URPGBaseWidget::Toggle()
{
    IsVisible() ? Hide() : Show();
}

IRPGGameState* URPGBaseWidget::GetGameState() const
{
    return Cast<IRPGGameState>(UGameplayStatics::GetGameInstance(this));
}

void URPGBaseWidget::Update()
{
}

FTimerManager& URPGBaseWidget::GetWorldTimerManager() const
{
    return GetWorld()->GetTimerManager();
}

void URPGBaseWidget::HideAnimationFinished()
{
    SetVisibility(ESlateVisibility::Hidden);
}
