// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/RPGPlayerController.h"
#include "Interfaces/RPGHUDPlayerController.h"
#include "RPGGamePlayerController.generated.h"

UCLASS()
class ACTIONRPG_API ARPGGamePlayerController final : public ARPGPlayerController, public IRPGHUDPlayerController
{
    GENERATED_BODY()
public:
    virtual FOnWidgetToggled& OnInventoryWidgetToggled() override;
    virtual FOnWidgetToggled& OnPauseWidgetToggled() override;
    virtual void ContinueGame() override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
private:
    FOnWidgetToggled OnInventoryWidetToggledEvent;
    FOnWidgetToggled OnPauseWidgetToggledEvent;

    bool bIsInventoryShown = false;
    bool bIsPauseShown = false;

    void ToggleInventory();
    void UpdateInputMode();
    void TogglePauseWidget();
};