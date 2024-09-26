// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Controllers/RPGAnimalAIController.h"
#include "Interfaces/RPGPlayerInfo.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Components/AI/RPGAIComponent.h"
#include "Components/AI/RPGPatrolAIComponent.h"
#include "Components/AI/RPGAggressiveComponent.h"
#include "Interfaces/RPGAnimalInfo.h"
#include "Navigation/PathFollowingComponent.h"

ARPGAnimalAIController::ARPGAnimalAIController() : Super()
{
    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

    PatrolAIComponent = CreateDefaultSubobject<URPGPatrolAIComponent>(TEXT("PatrolAIComponent"));

    AggressiveComponent = CreateDefaultSubobject<URPGAggressiveComponent>(TEXT("AgressiveComponent"));

    UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
    check(SightSense);
    SightSense->DetectionByAffiliation.bDetectNeutrals = true;
    SightSense->SightRadius = 1000.f;
    SightSense->LoseSightRadius = 1200.f;
    SightSense->PeripheralVisionAngleDegrees = 180.f;
    check(AIPerceptionComponent);
    AIPerceptionComponent->ConfigureSense(*SightSense);
    AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnPerceptionUpdated);
}

void ARPGAnimalAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    DetectActor(Actor);
}

void ARPGAnimalAIController::DetectActor(AActor* InActor)
{
    if (Cast<IRPGPlayerInfo>(InActor))
    {
        AggressiveComponent->SetEnemy(InActor);
        ActivateComponent(AggressiveComponent);
    }
}

void ARPGAnimalAIController::TakeDamageFromActor(AActor* DamageInstigator)
{
    AggressiveComponent->SetEnemy(DamageInstigator);
    ActivateComponent(AggressiveComponent);
}

void ARPGAnimalAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);
    check(CurrentAIComponent);
    CurrentAIComponent->OnMoveCompleted(Result.IsSuccess());
}

void ARPGAnimalAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    ActivateComponent(PatrolAIComponent);
}

void ARPGAnimalAIController::ActivateComponent(URPGAIComponent* InComponent)
{
    check(InComponent);
    if (CurrentAIComponent != InComponent)
    {
        if (CurrentAIComponent)
        {
            CurrentAIComponent->Stop();
        }
        CurrentAIComponent = InComponent;
        CurrentAIComponent->Start(this);
    }
}
