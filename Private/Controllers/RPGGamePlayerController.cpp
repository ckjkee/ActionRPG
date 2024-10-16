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
    InputComponent->BindAction("Pause",IE_Pressed,this, &ThisClass::TogglePauseWidget).bExecuteWhenPaused = true;
}

void ARPGGamePlayerController::ToggleInventory()
{
    bIsInventoryShown = !bIsInventoryShown;
    OnInventoryWidetToggledEvent.Broadcast();
    UpdateInputMode();
}

void ARPGGamePlayerController::UpdateInputMode()
{
    bShowMouseCursor = bIsInventoryShown || bIsPauseShown;
    if(bIsInventoryShown)
    {
        SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
    }
    else
    {
        SetInputMode(FInputModeGameOnly());
    }
}

void ARPGGamePlayerController::TogglePauseWidget()
{
    bIsPauseShown = !bIsPauseShown;
    SetPause(bIsPauseShown);
    UpdateInputMode();
    OnPauseWidgetToggledEvent.Broadcast();
}

FOnWidgetToggled& ARPGGamePlayerController::OnInventoryWidgetToggled()
{
    return OnInventoryWidetToggledEvent;
}

FOnWidgetToggled& ARPGGamePlayerController::OnPauseWidgetToggled()
{
    return OnPauseWidgetToggledEvent;
}

void ARPGGamePlayerController::ContinueGame()
{
    TogglePauseWidget();
}
