// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "WorldActors/Items/RPGInteractableObject.h"

ARPGInteractableObject::ARPGInteractableObject()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);
}
