// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/RPGPlayerController.h"
#include "RPGMainMenuPlayerController.generated.h"


UCLASS()
class ACTIONRPG_API ARPGMainMenuPlayerController final : public ARPGPlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
};
