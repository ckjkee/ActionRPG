// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RPGCharacter.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "Interfaces/RPGInteract.h"
#include "RPGAnimalCharacter.generated.h"

class UBoxComponent;
class URPGInteractWidgetComponent;
class URPGHealthWidgetComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGAnimalCharacter final : public ARPGCharacter, public IRPGAnimalInfo, public IRPGInteract
{
    GENERATED_BODY()

public:
    ARPGAnimalCharacter();

    virtual void SetMovementSpeed(const float Value) override;
    virtual void SetLevelForSpawn(uint16 InLevel) override;

    virtual void Interact(AActor* InActor) override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BlockingCollision;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGInteractWidgetComponent* InteractWidgetComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGHealthWidgetComponent* HealthWidgetComponent;
};
