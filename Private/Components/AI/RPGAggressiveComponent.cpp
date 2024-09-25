// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/AI/RPGAggressiveComponent.h"
#include "Interfaces/RPGAttributes.h"

void URPGAggressiveComponent::Start(AAIController* InAIController)
{
    Super::Start(InAIController);
    SetMovementType(EMovementType::Sprinting);
    DelayAttackSpeed = AnimalAttributes->GetAttackSpeed();
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::MoveToTarget, DelayAttackSpeed, true, 0.f); // TODO: AttackSpeed Need to be reversed or reworked
}

void URPGAggressiveComponent::OnMoveCompleted(const bool bIsSuccess)
{
    Super::OnMoveCompleted(bIsSuccess);
    if (bIsSuccess)
    {
        AttackTarget();
    }
}

void URPGAggressiveComponent::Stop()
{
    Super::Stop();
    GetWorldTimerManager().ClearTimer(TimerHandle);
}

void URPGAggressiveComponent::SetEnemy(AActor* InEnemy)
{
    Enemy = InEnemy;
}

void URPGAggressiveComponent::AttackTarget()
{
    UE_LOG(LogTemp, Warning, TEXT("Damage Caused = %f"), AnimalAttributes->GetCurrentDamage()); // TODO DELETE
}

void URPGAggressiveComponent::MoveToTarget()
{
    if (Enemy)
    {
        MoveToActor(Enemy, AcceptanceRadius);
    }
}
