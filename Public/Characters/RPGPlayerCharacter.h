// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "Characters/RPGCharacter.h"
#include "CoreMinimal.h"
#include "RPGPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGPlayerCharacter final : public ARPGCharacter
{
    GENERATED_BODY()

public:
    ARPGPlayerCharacter();

    virtual void Tick(float DeltaSeconds) override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

private:
    void MoveForwardBackward(const float Value);
    void MoveLeftRight(const float Value);
    void Move(const EAxis::Type& axis, const float Value);
};
