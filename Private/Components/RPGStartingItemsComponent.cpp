// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGStartingItemsComponent.h"
#include "Interfaces/RPGInventory.h"
#include "Utility/RPGHelperFunctions.h"
#include "Utility/RPGItemHelper.h"
#include "Kismet/KismetMathLibrary.h"

void URPGStartingItemsComponent::BeginPlay()
{
    Super::BeginPlay();
    AddStartingItems();
}

void URPGStartingItemsComponent::AddStartingItems()
{
    IRPGInventory* Inventory = RPGHelperFunctions::GetComponentByInterface<IRPGInventory>(GetOwner());
    check(Inventory);
    for (const FStartingItemInfo& ItemInfo : Items)
    {
        for (uint32 i = 0; i < ItemInfo.Count; ++i)
        {
            if (UKismetMathLibrary::RandomBoolWithWeight(ItemInfo.Probability))
            {
                Inventory->AddItem(ItemInfo.ItemInfo.RowName, ItemInfo.Count);
            }
        }
    }
}

