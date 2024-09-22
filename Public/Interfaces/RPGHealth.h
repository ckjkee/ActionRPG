// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGHealth.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDead)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class URPGHealth : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IRPGHealth
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    virtual inline FOnDead& OnDead() = 0;
};
