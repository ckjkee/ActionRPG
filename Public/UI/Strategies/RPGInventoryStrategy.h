// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RPGInventoryStrategy.generated.h"


UCLASS(Abstract)
class ACTIONRPG_API URPGInventoryStrategy : public UObject
{
	GENERATED_BODY()
public:
	virtual void OnClicked(const FName& InRowName) const;
};
