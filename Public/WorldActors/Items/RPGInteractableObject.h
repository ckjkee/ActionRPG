// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGInteractableObject.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API ARPGInteractableObject : public AActor
{
    GENERATED_BODY()
public:
    ARPGInteractableObject();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;
};
