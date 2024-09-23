// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Interfaces/RPGAIController.h"
#include "RPGAnimalAIController.generated.h"

class UAIPerceptionComponent;
struct FAIStimulus;

UCLASS()
class ACTIONRPG_API ARPGAnimalAIController final : public AAIController, public IRPGAIController
{
    GENERATED_BODY()

public:
    ARPGAnimalAIController();

    virtual void DetectActor(AActor* InActor) override;
    virtual void TakeDamageFromActor(AActor* DamageInstigator) override;

protected:
    virtual void OnPossess(APawn* InPawn) override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UAIPerceptionComponent* AIPerceptionComponent;

    UFUNCTION()
    void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
