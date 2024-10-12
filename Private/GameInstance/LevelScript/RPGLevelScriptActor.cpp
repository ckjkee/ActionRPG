// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "GameInstance/LevelScript/RPGLevelScriptActor.h"
#include "Interfaces/RPGGameState.h"

void ARPGLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::TestLoadingDelay, 1.f);
}

//Intentional slowdown (delete if unneeded)
void ARPGLevelScriptActor::TestLoadingDelay() const
{
	IRPGGameState* GameState = Cast<IRPGGameState>(GetGameInstance());
	check(GameState);
	GameState->LevelLoaded();
}
