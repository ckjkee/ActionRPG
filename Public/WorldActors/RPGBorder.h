// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGBorder.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGBorder final : public AActor
{
    GENERATED_BODY()

public:
    ARPGBorder();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* ExternalBoxCollision;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* InternalBoxCollision;

private:
    UPROPERTY()
    AActor* Player;

    FVector Location;

    UFUNCTION()
    void OnExternalBoxCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnInternalBoxCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
