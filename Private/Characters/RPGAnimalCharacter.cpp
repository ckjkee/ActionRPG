// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGAnimalCharacter.h"
#include "Components/BoxComponent.h"


ARPGAnimalCharacter::ARPGAnimalCharacter() : Super()
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    BlockingCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BlockingCollision"));
    check(BlockingCollision);
    BlockingCollision->SetupAttachment(GetRootComponent());
    BlockingCollision->SetCollisionProfileName("Pawn");
}

