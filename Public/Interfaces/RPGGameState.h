// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGGameState.generated.h"

UINTERFACE(MinimalAPI)
class URPGGameState : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGGameState
{
	GENERATED_BODY()

public:
	virtual void NewGame() = 0;
	virtual void QuitGame() const = 0;
};
