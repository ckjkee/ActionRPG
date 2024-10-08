// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/RPGHudWidget.h"
#include "RPGGameHudWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ACTIONRPG_API URPGGameHudWidget final : public URPGHudWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
};
