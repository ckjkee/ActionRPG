// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Animations/RPGPawnAnimInstance.h"
#include "KismetAnimationLibrary.h"

void URPGPawnAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    Pawn = TryGetPawnOwner();
    Movement = Cast<IMovementInterface>(Pawn);
}

void URPGPawnAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    if (Pawn)
    {
        speed = Pawn->GetVelocity().Size();
        Direction = UKismetAnimationLibrary::CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
        if (Movement)
        {
            bIsFalling = Movement->GetIsFalling();
        }
    }
}
