// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/RPGHudWidget.h"
#include "RPGMainMenuHUDWidget.generated.h"

class URPGButtonWidget;

UCLASS(Abstract)
class ACTIONRPG_API URPGMainMenuHUDWidget final : public URPGHudWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
	URPGButtonWidget* NewGameButton;

	UPROPERTY(meta = (BindWidget))
	URPGButtonWidget* QuitGameButton;

private:
	UFUNCTION()
	void OnNewGameButtonClicked();
	
	UFUNCTION()
	void OnQuitGameButtonClicked();
};
