// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGHUDPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventoryWidgetToggled)

UINTERFACE(MinimalAPI)
class URPGHUDPlayerController : public UInterface
{
	GENERATED_BODY()
};

class ACTIONRPG_API IRPGHUDPlayerController
{
	GENERATED_BODY()

public:
	virtual FOnInventoryWidgetToggled& OnInventoryWidgetToggled() = 0;
};
