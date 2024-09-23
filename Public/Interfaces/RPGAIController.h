// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGAIController.generated.h"

UINTERFACE(MinimalAPI)
class URPGAIController : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IRPGAIController
{
	GENERATED_BODY()

public:
    virtual void DetectActor(AActor* InActor) = 0;
    virtual void TakeDamageFromActor(AActor* DamageInstigator) = 0;
};
