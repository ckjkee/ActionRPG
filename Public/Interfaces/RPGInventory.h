// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RPGInventory.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventroyChanged)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAddedItem, const FName&, const uint32)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRemovedItem, const FName&, const uint32)

UINTERFACE(MinimalAPI)
class URPGInventory : public UInterface
{
	GENERATED_BODY()
};

class ACTIONRPG_API IRPGInventory
{
	GENERATED_BODY()

public:
	virtual FOnInventroyChanged& OnInventoryChanged() = 0;
	virtual void AddItem(const FName& ItemRowName,const uint32 Count = 1) = 0;
	virtual bool RemoveItem(const FName& ItemRowName,const uint32 Count = 1) = 0;
	virtual void TransferFromInventory(IRPGInventory* OtherInventory) = 0;
	virtual bool HasItem(const FName& ItemRowName) const = 0;
	virtual uint32 GetItemCount(const FName& ItemRowName) const = 0;
	virtual const TMap<FName, uint32>& GetItems() const = 0;
	virtual const FName GetFirstWeapon() const = 0;
	virtual FOnAddedItem& OnAddedItem() = 0;
	virtual FOnRemovedItem& OnRemovedItem() = 0;
};
