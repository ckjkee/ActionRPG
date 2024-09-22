// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "Characters/RPGCharacter.h"
#include "CoreMinimal.h"
#include "RPGPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URPGExperienceComponent;
class URPGInteractComponent;
class URPGResurrectComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGPlayerCharacter final : public ARPGCharacter
{
    GENERATED_BODY()

public:
    ARPGPlayerCharacter();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGExperienceComponent* ExperienceComponent;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGInteractComponent* InteractComponent;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGResurrectComponent* ResurrectComponent;

private:
    void OnLeftInteractingActor(AActor* InActor);
    void OnEnteredInteractingActor(AActor* InActor);
    void MoveForwardBackward(const float Value);
    void MoveLeftRight(const float Value);
    void Move(const EAxis::Type& axis, const float Value);
};
