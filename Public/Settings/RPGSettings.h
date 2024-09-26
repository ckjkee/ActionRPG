// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "RPGSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Game Settings"))
class ACTIONRPG_API URPGSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
    UPROPERTY(Config,EditDefaultsOnly, Category = "Data Tables")
	TSoftObjectPtr<UDataTable> ItemsDataTable;
};
