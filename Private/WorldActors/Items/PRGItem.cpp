// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "WorldActors/Items/PRGItem.h"
#include "Utility/RPGHelperFunctions.h"
#include "Interfaces/RPGInventory.h"
#include "Utility/RPGItemHelper.h"

void APRGItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ItemRow.DataTable = FRPGItemHelper::GetDataTable();
	StaticMeshComponent->SetStaticMesh(FRPGItemHelper::GetItemStaticMesh(ItemRow.RowName));
}

void APRGItem::DoInteract(AActor* InActor)
{
	Super::DoInteract(InActor);
	IRPGInventory* Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(InActor);
	if(Inventory)
    {
		Inventory->AddItem(ItemRow.RowName);
		Destroy();
    }
}

FText APRGItem::GetObjectName() const
{
    return FRPGItemHelper::GetItemName(ItemRow.RowName);
}
