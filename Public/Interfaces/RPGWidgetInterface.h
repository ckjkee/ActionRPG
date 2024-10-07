// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGWidgetInterface.generated.h"

UINTERFACE(MinimalAPI)
class URPGWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class ACTIONRPG_API IRPGWidgetInterface
{
	GENERATED_BODY()

public:
	virtual void SetObjectName(const FText& ObjectName) const = 0;
	virtual void SetInteractText(const FText& InteractText) const = 0;
};
