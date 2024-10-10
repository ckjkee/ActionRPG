// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGInventory.h"
#include "RPGInventoryComponent.generated.h"


UCLASS()
class ACTIONRPG_API URPGInventoryComponent final : public URPGBaseComponent, public IRPGInventory
{
    GENERATED_BODY()

public:
    virtual FOnInventroyChanged& OnInventoryChanged() override;
    virtual void AddItem(const FName& ItemRowName, const uint32 Count = 1) override;
    virtual bool RemoveItem(const FName& ItemRowName, const uint32 Count = 1) override;
    virtual void TransferFromInventory(IRPGInventory* OtherInventory) override;
    virtual bool HasItem(const FName& ItemRowName) const override;
    virtual uint32 GetItemCount(const FName& ItemRowName) const override;
    virtual const TMap<FName, uint32>& GetItems() const override;
    virtual const FName GetFirstWeapon() const override; 

private:
    FOnInventroyChanged OnInventoryChangedEvent;
    TMap<FName, uint32> Items;
};
