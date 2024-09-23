// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGAttributes.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAttributesChanged, float /*CurrentHealth*/)

class IRPGComponents;

UINTERFACE(MinimalAPI)
class URPGAttributes : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGAttributes
{
	GENERATED_BODY()
public:
    virtual FOnAttributesChanged& OnAttributesChanged() = 0;
};
