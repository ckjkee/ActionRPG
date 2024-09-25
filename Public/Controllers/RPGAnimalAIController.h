// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Interfaces/RPGAIController.h"
#include "RPGAnimalAIController.generated.h"

class UAIPerceptionComponent;
class URPGAIComponent;
class URPGPatrolAIComponent;
class URPGAggressiveComponent;
struct FAIStimulus;

UCLASS(Abstract)
class ACTIONRPG_API ARPGAnimalAIController final : public AAIController, public IRPGAIController
{
    GENERATED_BODY()

public:
    ARPGAnimalAIController();

    virtual void DetectActor(AActor* InActor) override;
    virtual void TakeDamageFromActor(AActor* DamageInstigator) override;
    virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

protected:
    virtual void OnPossess(APawn* InPawn) override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UAIPerceptionComponent* AIPerceptionComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGAIComponent* CurrentAIComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGPatrolAIComponent* PatrolAIComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URPGAggressiveComponent* AggressiveComponent;

    UFUNCTION()
    void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
