// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/RPGGameState.h"
#include "RPGGameInstance.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API URPGGameInstance final : public UGameInstance, public IRPGGameState
{
    GENERATED_BODY()
public:
    virtual void NewGame() override;
    virtual void QuitGame() const override;
    virtual void LevelLoaded() override;
    virtual void ReturnToMainMenu() override;
    virtual FOnLoadingStarted& OnLoadingStarted() override;
    virtual FOnLoadingEnded& OnLoadingEnded() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<UWorld> GameLevel;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<UWorld> MainMenuLevel;

    TSoftObjectPtr<UWorld> Level;

    void StartLoadingLevel(TSoftObjectPtr<UWorld>& InLevel);
    void OpenLevel() const;

    float DelayBeforeLoading = 0.5f;

    FOnLoadingStarted OnLoadingStartedEvent;
    FOnLoadingEnded OnLoadingEndedEvent;
};
