// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/AI/RPGAIComponent.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "AIController.h"

void URPGAIComponent::Start(AAIController* InAIController)
{
    AIController = InAIController;
    check(AIController);
    Animal = Cast<IRPGAnimalInfo>(AIController->GetPawn());
}

void URPGAIComponent::Stop()
{
}

void URPGAIComponent::OnMoveCompleted(const bool bIsSuccess)
{
}

void URPGAIComponent::SetMovementType(const EMovementType& InMovementType)
{
    check(Animal);

    switch (InMovementType)
    {
    case EMovementType::Walking:
        Animal->SetMovementSpeed(Speeds[InMovementType]);
    case EMovementType::Running:
        Animal->SetMovementSpeed(Speeds[InMovementType]);
    case EMovementType::Sprinting:
        Animal->SetMovementSpeed(Speeds[InMovementType]);
    default:
        break;
    }
}

void URPGAIComponent::MoveToLocation(const FVector& Location) const
{
    check(AIController);
    AIController->MoveToLocation(Location);
}
