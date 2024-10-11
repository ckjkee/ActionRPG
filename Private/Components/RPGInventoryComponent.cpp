// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGInventoryComponent.h"
#include "Utility/RPGItemHelper.h"

FOnInventroyChanged& URPGInventoryComponent::OnInventoryChanged()
{
    return OnInventoryChangedEvent;
}

void URPGInventoryComponent::AddItem(const FName& ItemRowName, const uint32 Count)
{
    check(Count > 0);
    if (Items.Contains(ItemRowName))
    {
        Items[ItemRowName] += Count;
    }
    else
    {
        Items.Add(ItemRowName, Count);
    }
    OnInventoryChangedEvent.Broadcast();
    OnAddedItemEvent.Broadcast(ItemRowName, Count);
}

bool URPGInventoryComponent::RemoveItem(const FName& ItemRowName, const uint32 Count)
{
    if (!Items.Contains(ItemRowName))
    {
        return false;
    }
    if (Items[ItemRowName] < Count)
    {
        return false;
    }

    Items[ItemRowName] -= Count;

    if (Items[ItemRowName] == 0)
    {
        Items.Remove(ItemRowName);
    }
    OnInventoryChangedEvent.Broadcast();
    OnRemovedItemEvent.Broadcast(ItemRowName, Count);
    return true;
}

void URPGInventoryComponent::TransferFromInventory(IRPGInventory* OtherInventory)
{
    check(OtherInventory);
    const TMap<FName, uint32> OtherItems = OtherInventory->GetItems();
    for (const TPair<FName, uint32>& Item : OtherItems)
    {
        AddItem(Item.Key, Item.Value);
        if (!OtherInventory->RemoveItem(Item.Key, Item.Value))
        {
            checkNoEntry();
        }
    }
}

bool URPGInventoryComponent::HasItem(const FName& ItemRowName) const
{
    return Items.Contains(ItemRowName);
}

uint32 URPGInventoryComponent::GetItemCount(const FName& ItemRowName) const
{
    if (Items.Contains(ItemRowName))
    {
        return Items[ItemRowName];
    }
    return 0;
}

const TMap<FName, uint32>& URPGInventoryComponent::GetItems() const
{
    return Items;
}

const FName URPGInventoryComponent::GetFirstWeapon() const
{
    for(const TPair<FName,uint32> Item : Items)
    {
        const ERPGItemCategory Category = FRPGItemHelper::GetItemCategory(Item.Key);
        if(Category == ERPGItemCategory::Weapon)
        {
            return Item.Key;
        }
    }
    return FName();
}

FOnAddedItem& URPGInventoryComponent::OnAddedItem()
{
    return OnAddedItemEvent;
}

FOnRemovedItem& URPGInventoryComponent::OnRemovedItem()
{
    return OnRemovedItemEvent;
}
