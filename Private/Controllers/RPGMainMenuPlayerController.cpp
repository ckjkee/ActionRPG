// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Controllers/RPGMainMenuPlayerController.h"

void ARPGMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	SetInputMode(FInputModeUIOnly());
}
