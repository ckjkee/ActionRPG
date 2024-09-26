// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldActors/Items/RPGInteractableObject.h"
#include "PRGItem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ACTIONRPG_API APRGItem : public ARPGInteractableObject
{
	GENERATED_BODY()
public:
	virtual void OnConstruction(const FTransform& Transform) override;
private:
    UPROPERTY(EditAnywhere, Category = "Settings")
	FDataTableRowHandle ItemRow;
};
