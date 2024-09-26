// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "WorldActors/RPGAnimalSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"

ARPGAnimalSpawner::ARPGAnimalSpawner() : Super()
{
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    check(BoxComponent);
    SetRootComponent(BoxComponent);
}

void ARPGAnimalSpawner::BeginPlay()
{
    Super::BeginPlay();
    for (uint16 i = 0; i < AmountToSpawn; ++i)
    {
        Spawn();
    }
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::Check, CheckRate, true);
}

void ARPGAnimalSpawner::Spawn()
{
    check(GetWorld());
    AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetSpawnLocation(), FRotator::ZeroRotator);
    if (SpawnedActor)
    {
        ActorsArray.Add(SpawnedActor);
    }
    else
    {
        Spawn();
    }
}

FVector ARPGAnimalSpawner::GetSpawnLocation() const
{
    check(BoxComponent);
    const FTransform BoxTransform{BoxComponent->GetComponentRotation(), BoxComponent->GetComponentLocation(), FVector::OneVector};

    const FVector RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(FVector::ZeroVector, BoxComponent->GetScaledBoxExtent());

    return UKismetMathLibrary::TransformLocation(BoxTransform, RandomPoint);
}

void ARPGAnimalSpawner::Check()
{
    const uint32 ActorsCount = ActorsArray.Num();
    for (uint32 i = 0; i < ActorsCount; ++i)
    {
        if (!IsValid(ActorsArray[i]))
        {
            ActorsArray.RemoveAt(i);
            Spawn();
        }
    }
}
