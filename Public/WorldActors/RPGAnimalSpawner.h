// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGAnimalSpawner.generated.h"

class UBoxComponent;

UCLASS()
class ACTIONRPG_API ARPGAnimalSpawner : public AActor
{
    GENERATED_BODY()

public:
    ARPGAnimalSpawner();

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle TimerHandle;

    UPROPERTY(EditAnywhere, Category = "Spawn Settings", meta = (ClampMin = "0", UIMin = "0"))
    float CheckRate = 5.f;

    UPROPERTY(EditAnywhere, Category = "Spawn Settings")
    TSubclassOf<AActor> ActorToSpawn;

    UPROPERTY(VisibleAnywhere, Category = "Spawn Settings")
    UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere, Category = "Spawn Settings")
    uint16 AmountToSpawn = 5;

    TArray<AActor*> ActorsArray;

    void Spawn();

    FVector GetSpawnLocation() const;

    void Check();
};
