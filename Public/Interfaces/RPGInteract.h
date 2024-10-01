// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGInteract.generated.h"

UINTERFACE(MinimalAPI)
class URPGInteract : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGInteract
{
	GENERATED_BODY()

public:
	virtual void Interact(AActor* InActor) = 0;
	virtual void OnEnter() = 0;
	virtual void OnLeave() = 0;
};
