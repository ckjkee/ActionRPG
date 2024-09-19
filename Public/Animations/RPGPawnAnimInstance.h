// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Interfaces/MovementInterface.h"
#include "RPGPawnAnimInstance.generated.h"

/**
 *
 */
UCLASS(Abstract)
class ACTIONRPG_API URPGPawnAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float speed = 0.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Direction = 0.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bIsFalling = false;

private:
    UPROPERTY()
    APawn* Pawn;

    IMovementInterface* Movement;
};
