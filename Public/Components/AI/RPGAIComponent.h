// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "RPGAIComponent.generated.h"

class AAIController;
class IRPGAnimalInfo;

UENUM(BlueprintType)
enum class EMovementType : uint8
{
    Walking = 0,
    Running,
    Sprinting
};

UCLASS(Abstract)
class ACTIONRPG_API URPGAIComponent : public URPGBaseComponent
{
    GENERATED_BODY()
public:
    virtual void Start(AAIController* InAIController);
    virtual void Stop();
    virtual void OnMoveCompleted(const bool bIsSuccess);
    virtual void SetMovementType(const EMovementType& InMovementType);

protected:
    void MoveToLocation(const FVector& Location) const;

private:
    UPROPERTY(EditDefaultsOnly)
    TMap<EMovementType, float> Speeds{{EMovementType::Walking, 200}, {EMovementType::Running, 600}, {EMovementType::Sprinting, 900}};

    AAIController* AIController;

    IRPGAnimalInfo* Animal;
};
