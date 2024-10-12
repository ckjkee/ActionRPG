// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "HUD/RPGMainMenuHUDWidget.h"
#include "UI/RPGButtonWidget.h"
#include "Interfaces/RPGGameState.h"


void URPGMainMenuHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(NewGameButton);
	check(QuitGameButton);

	NewGameButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnNewGameButtonClicked);
	QuitGameButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnQuitGameButtonClicked);

}

void URPGMainMenuHUDWidget::OnNewGameButtonClicked()
{
	check(GetGameState());
	GetGameState()->NewGame();
}

void URPGMainMenuHUDWidget::OnQuitGameButtonClicked()
{
	check(GetGameState());
	GetGameState()->QuitGame();
}
