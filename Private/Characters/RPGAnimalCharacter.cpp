// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGAnimalCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/RPGExperienceComponent.h"
#include "Components/RPGInteractWidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ARPGAnimalCharacter::ARPGAnimalCharacter() : Super()
{
    bUseControllerRotationYaw = false;

    check(GetCharacterMovement());
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0,180,0);

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    BlockingCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BlockingCollision"));
    check(BlockingCollision);
    BlockingCollision->SetupAttachment(GetRootComponent());
    BlockingCollision->SetCollisionProfileName("Pawn");

    InteractWidgetComponent = CreateDefaultSubobject<URPGInteractWidgetComponent>(TEXT("InteractWidget"));
    check(InteractWidgetComponent);
    InteractWidgetComponent->SetupAttachment(GetMesh());
}

void ARPGAnimalCharacter::SetMovementSpeed(const float Value)
{
    check(GetCharacterMovement());
    GetCharacterMovement()->MaxWalkSpeed = Value;
}

void ARPGAnimalCharacter::SetLevelForSpawn(uint16 InLevel)
{
    ExperienceComponent->SetLevel(InLevel);
}

