// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGRowName.generated.h"

UINTERFACE(MinimalAPI)
class URPGRowName : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGRowName
{
	GENERATED_BODY()

public:
	virtual void SetRowName(const FName& InRowName) = 0;
	virtual FName GetRowName() = 0;
};
