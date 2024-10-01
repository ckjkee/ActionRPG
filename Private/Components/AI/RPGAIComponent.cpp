// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/AI/RPGAIComponent.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "Interfaces/RPGAttributes.h"
#include "Utility/RPGHelperFunctions.h"
#include "AIController.h"

void URPGAIComponent::Start(AAIController* InAIController)
{
    AIController = InAIController;
    check(AIController);
    Animal = Cast<IRPGAnimalInfo>(AIController->GetPawn());
    APawn* ControlledPawn = AIController->GetPawn();
    AnimalAttributes = RPGHelperFunctions::GetComponentByInterface<IRPGAttributes>(ControlledPawn);
}

void URPGAIComponent::Stop()
{
    check(AIController);
    AIController->StopMovement();
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
        break;
    case EMovementType::Running:
        Animal->SetMovementSpeed(Speeds[InMovementType]);
        break;
    case EMovementType::Sprinting:
        Animal->SetMovementSpeed(Speeds[InMovementType]);
        break;
    default:
        break;
    }
}

void URPGAIComponent::MoveToLocation(const FVector& Location) const
{
    check(AIController);
    AIController->MoveToLocation(Location);
}

void URPGAIComponent::MoveToActor(AActor* InActor, float AcceptanceRadius) const
{
    check(AIController);
    AIController->MoveToActor(InActor, AcceptanceRadius);
}
