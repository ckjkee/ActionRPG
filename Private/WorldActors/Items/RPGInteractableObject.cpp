// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "WorldActors/Items/RPGInteractableObject.h"
#include "Components/RPGInteractWidgetComponent.h"

ARPGInteractableObject::ARPGInteractableObject()
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    SetRootComponent(StaticMeshComponent);

    InteractWidgetComponent = CreateDefaultSubobject<URPGInteractWidgetComponent>(TEXT("InteractWidget"));
    check(InteractWidgetComponent);
    InteractWidgetComponent->SetupAttachment(StaticMeshComponent);
}

void ARPGInteractableObject::Interact(AActor* InActor)
{
    if (CanInteract())
    {
        DoInteract(InActor);
    }
}

void ARPGInteractableObject::OnEnter()
{
    if (CanInteract())
    {
        check(InteractWidgetComponent);
        InteractWidgetComponent->SetVisibility(true);
    }
}

void ARPGInteractableObject::OnLeave()
{
    check(InteractWidgetComponent);
    InteractWidgetComponent->SetVisibility(false);
}

void ARPGInteractableObject::BeginPlay()
{
    Super::BeginPlay();
    check(InteractWidgetComponent);
    InteractWidgetComponent->SetObjectName(GetObjectName());
}

bool ARPGInteractableObject::CanInteract() const
{
    return true;
}

void ARPGInteractableObject::DoInteract(AActor* InActor)
{
}

FText ARPGInteractableObject::GetObjectName() const
{
    return FText();
}
