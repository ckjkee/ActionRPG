// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/RPGInteract.h"
#include "RPGInteractableObject.generated.h"

class URPGInteractWidgetComponent;

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
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGInteractWidgetComponent* InteractWidgetComponent;

    virtual bool CanInteract() const;
    virtual void DoInteract(AActor* InActor);
    virtual FText GetObjectName() const;
};
