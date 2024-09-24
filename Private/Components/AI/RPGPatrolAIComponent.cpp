// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Components/AI/RPGPatrolAIComponent.h"
#include "NavigationSystem.h"

void URPGPatrolAIComponent::Start(AAIController* InAIController)
{
	Super::Start(InAIController);
	StartLocation = GetOwner()->GetActorLocation();
	SetMovementType(EMovementType::Walking);
	GetWorldTimerManager().SetTimer(TimerHandleForNextPoint, this, &ThisClass::MoveToNextPoint,DelayForNextPoint);
}

void URPGPatrolAIComponent::OnMoveCompleted(const bool bIsSuccess)
{
	Super::OnMoveCompleted(bIsSuccess);
	GetWorldTimerManager().SetTimer(TimerHandleForNextPoint, this, &ThisClass::MoveToNextPoint,DelayForNextPoint);
}

void URPGPatrolAIComponent::Stop()
{
	Super::Stop();
	GetWorldTimerManager().ClearTimer(TimerHandleForNextPoint);
}

void URPGPatrolAIComponent::MoveToNextPoint() const
{
	MoveToLocation(GetNextPointLocation());
}

FVector URPGPatrolAIComponent::GetNextPointLocation() const
{
	FNavLocation ResultLocation;
    const UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	check(NavSys);
	NavSys->GetRandomReachablePointInRadius(StartLocation,RadiusToPatrol,ResultLocation);
	
	DrawDebugSphere(GetWorld(), ResultLocation.Location, 200.f, 10, FColor::Red,false, 5.f); // TODO DELETE
	return ResultLocation.Location;
}
