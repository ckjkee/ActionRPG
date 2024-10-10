// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Controllers/RPGGamePlayerController.h"

void ARPGGamePlayerController::BeginPlay()
{
    Super::BeginPlay();
    UpdateInputMode();
}

void ARPGGamePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    check(InputComponent);
    InputComponent->BindAction("Inventory", IE_Pressed, this, &ThisClass::ToggleInventory);
}

void ARPGGamePlayerController::ToggleInventory()
{
    bIsInventoryShown = !bIsInventoryShown;
    OnInventoryWidetToggledEvent.Broadcast();
    UpdateInputMode();
}

void ARPGGamePlayerController::UpdateInputMode()
{
    bShowMouseCursor = bIsInventoryShown;
    if(bIsInventoryShown)
    {
        SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
    }
    else
    {
        SetInputMode(FInputModeGameOnly());
    }
}

FOnInventoryWidgetToggled& ARPGGamePlayerController::OnInventoryWidgetToggled()
{
    return OnInventoryWidetToggledEvent;
}
