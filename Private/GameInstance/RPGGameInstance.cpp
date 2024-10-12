// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "GameInstance/RPGGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void URPGGameInstance::NewGame()
{
    StartLoadingLevel(GameLevel);
}

void URPGGameInstance::StartLoadingLevel(TSoftObjectPtr<UWorld>& InLevel)
{
    Level = InLevel;
    OnLoadingStartedEvent.Broadcast();

    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::OpenLevel, DelayBeforeLoading);
}

void URPGGameInstance::OpenLevel() const
{
    UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}

void URPGGameInstance::QuitGame() const
{
    UKismetSystemLibrary::QuitGame(this, GetPrimaryPlayerController(), EQuitPreference::Quit, true);
}

void URPGGameInstance::LevelLoaded()
{
    OnLoadingEndedEvent.Broadcast();
}

FOnLoadingStarted& URPGGameInstance::OnLoadingStarted()
{
    return OnLoadingStartedEvent;
}

FOnLoadingEnded& URPGGameInstance::OnLoadingEnded()
{
    return OnLoadingEndedEvent;
}
