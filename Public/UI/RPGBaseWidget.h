// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPGBaseWidget.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API URPGBaseWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    void Show();
    void Hide();

protected:
    UPROPERTY(Transient, meta = (BindWidgetAnimOptional))
    UWidgetAnimation* HideAnimation;

    virtual void Update();
    FTimerManager& GetWorldTimerManager() const;

private:
    FWidgetAnimationDynamicEvent OnAnimationFinishedEvent;

    UFUNCTION()
    void HideAnimationFinished();
};
