// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Characters/RPGAnimalCharacter.h"
#include "Components/BoxComponent.h"

ARPGAnimalCharacter::ARPGAnimalCharacter() : Super()
{
    BlockingCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BlockingCollision"));
    check(BlockingCollision);
    BlockingCollision->SetupAttachment(GetRootComponent());
    BlockingCollision->SetCollisionProfileName("Pawn");
}
