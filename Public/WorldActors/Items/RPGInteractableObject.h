// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/RPGInteract.h"
#include "RPGInteractableObject.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API ARPGInteractableObject : public AActor, public IRPGInteract
{
    GENERATED_BODY()
public:
    ARPGInteractableObject();

    virtual void Interact(AActor* InActor) override final;
	virtual void OnEnter() override;
	virtual void OnLeave() override;

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

    virtual bool CanInteract() const;
    virtual void DoInteract(AActor* InActor);
};
