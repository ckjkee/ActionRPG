// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGPauseWidget.generated.h"

class URPGButtonWidget;

UCLASS()
class ACTIONRPG_API URPGPauseWidget : public URPGBaseWidget
{
    GENERATED_BODY()
protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    URPGButtonWidget* ContinueButton;

    UPROPERTY(meta = (BindWidget))
    URPGButtonWidget* ReturnToMainMenuButton;

    UPROPERTY(meta = (BindWidget))
    URPGButtonWidget* QuitGameButton;

private:
    UFUNCTION()
    void OnContinueButtonClicked();
    UFUNCTION()
    void OnReturnToMainMenuButtonClicked();
    UFUNCTION()
    void OnQuitGameButtonClicked();
};
