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

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSoftObjectPtr<UWorld> GameLevel;
};
