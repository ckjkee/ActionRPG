// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGFocus.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEntered, AActor*) 
DECLARE_MULTICAST_DELEGATE_OneParam(FOnLeft, AActor*)

UINTERFACE(MinimalAPI)
class URPGFocus : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IRPGFocus
{
	GENERATED_BODY()

public:
	virtual FOnEntered& OnEnter() = 0;
	virtual FOnLeft& OnLeft() = 0;
};
