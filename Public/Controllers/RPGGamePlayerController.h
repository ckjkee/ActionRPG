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
    virtual FOnInventoryWidgetToggled& OnInventoryWidgetToggled() override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
private:
    FOnInventoryWidgetToggled OnInventoryWidetToggledEvent;

    bool bIsInventoryShown = false;

    void ToggleInventory();
    void UpdateInputMode();
};