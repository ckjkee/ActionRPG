// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "UI/RPGPauseWidget.h"
#include "UI/RPGButtonWidget.h"
#include "Interfaces/RPGGameState.h"
#include "Interfaces/RPGHUDPlayerController.h"

void URPGPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(ContinueButton);
	check(ReturnToMainMenuButton);
	check(QuitGameButton);

	ContinueButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnContinueButtonClicked);
	ReturnToMainMenuButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnReturnToMainMenuButtonClicked);
	QuitGameButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnQuitGameButtonClicked);
}

void URPGPauseWidget::OnContinueButtonClicked()
{
	IRPGHUDPlayerController* HUDPlayerController = Cast<IRPGHUDPlayerController>(GetOwningPlayer());
	check(HUDPlayerController);
	HUDPlayerController->ContinueGame();
}

void URPGPauseWidget::OnReturnToMainMenuButtonClicked()
{
	check(GetGameState());
	GetGameState()->ReturnToMainMenu();
}

void URPGPauseWidget::OnQuitGameButtonClicked()
{
	check(GetGameState());
	GetGameState()->QuitGame();
}
