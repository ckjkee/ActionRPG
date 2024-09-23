// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Controllers/RPGAnimalAIController.h"
#include "Interfaces/RPGPlayerInfo.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"

ARPGAnimalAIController::ARPGAnimalAIController() : Super()
{
    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
    check(AIPerceptionComponent);

    UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
    check(SightSense);
    SightSense->DetectionByAffiliation.bDetectNeutrals = true;
    SightSense->SightRadius = 1000.f;
    SightSense->LoseSightRadius = 1200.f;
    SightSense->PeripheralVisionAngleDegrees = 180.f;
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
        UE_LOG(LogTemp, Warning, TEXT("DetectActor = %s"), *InActor->GetName()); // TODO Delete
    }
}

void ARPGAnimalAIController::TakeDamageFromActor(AActor* DamageInstigator)
{
    UE_LOG(LogTemp, Warning, TEXT("TakeDamageFromActor = %s"), *DamageInstigator->GetName()); // TODO DELETE
}

void ARPGAnimalAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    UE_LOG(LogTemp, Warning, TEXT("OnPossess = %s"), *InPawn->GetName()); // TODO DELETE
}
