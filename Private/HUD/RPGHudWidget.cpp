// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "HUD/RPGHudWidget.h"
#include "Interfaces/RPGGameState.h"
#include "UI/RPGLoadingScreen.h"

void URPGHudWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(LoadingScreenWidget);
	IRPGGameState* GameState = GetGameState();
	check(GameState);
	GameState->OnLoadingStarted().AddUObject(LoadingScreenWidget, &ThisClass::Show);
	GameState->OnLoadingEnded().AddUObject(LoadingScreenWidget, &ThisClass::Hide);
}
