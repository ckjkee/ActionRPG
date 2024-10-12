// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "GameInstance/RPGGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void URPGGameInstance::NewGame()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, GameLevel);
}

void URPGGameInstance::QuitGame() const
{
	UKismetSystemLibrary::QuitGame(this, GetPrimaryPlayerController(),EQuitPreference::Quit, true);
}
