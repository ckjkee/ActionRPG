// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "WorldActors/Items/RPGInteractableObject.h"

ARPGInteractableObject::ARPGInteractableObject()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);
}

void ARPGInteractableObject::Interact(AActor* InActor)
{
	if(CanInteract())
    {
		DoInteract(InActor);
    }
}

void ARPGInteractableObject::OnEnter()
{
}

void ARPGInteractableObject::OnLeave()
{
}

bool ARPGInteractableObject::CanInteract() const
{
    return true;
}

void ARPGInteractableObject::DoInteract(AActor* InActor)
{
	
}
