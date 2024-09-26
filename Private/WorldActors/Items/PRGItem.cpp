// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "WorldActors/Items/PRGItem.h"
#include "Utility/RPGItemHelper.h"

void APRGItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ItemRow.DataTable = FRPGItemHelper::GetDataTable();
	StaticMeshComponent->SetStaticMesh(FRPGItemHelper::GetItemStaticMesh(ItemRow.RowName));
}
