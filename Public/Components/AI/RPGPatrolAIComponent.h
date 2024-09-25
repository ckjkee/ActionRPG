// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/AI/RPGAIComponent.h"
#include "RPGPatrolAIComponent.generated.h"


UCLASS()
class ACTIONRPG_API URPGPatrolAIComponent : public URPGAIComponent
{
	GENERATED_BODY()
public:
	virtual void Start(AAIController* InAIController) override;
	virtual void OnMoveCompleted(const bool bIsSuccess) override;
	virtual void Stop() override;
private:
	void MoveToNextPoint() const;
	 FVector GetNextPointLocation() const;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float RadiusToPatrol = 2000.f;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
	float DelayForNextPoint = 5.f;

	FVector StartLocation = FVector::ZeroVector;
	FTimerHandle TimerHandleForNextPoint;

};
