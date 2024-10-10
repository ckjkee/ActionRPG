// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Utility/RPGItemHelper.h"
#include "Utility/RPGDataTableHelper.h"
#include "Settings/RPGSettings.h"
#include "Bases/CoreTypes/RPGTypes.h"

const UDataTable* FRPGItemHelper::GetDataTable()
{
    const URPGSettings* GameSettings =  GetDefault<URPGSettings>();
    check(GameSettings);
    return GameSettings->ItemsDataTable.LoadSynchronous();
}

const FRPGItemInfo* FRPGItemHelper::GetItemInfo(const FName& InRowName)
{
    return FRPGDataTableHelper::FindRow<FRPGItemInfo>(GetDataTable(), InRowName);
}

FText FRPGItemHelper::GetItemName(const FName& InRowName)
{
    const FRPGItemInfo* ItemInfo = GetItemInfo(InRowName);
    check(ItemInfo);
    return ItemInfo->Name;
}

UStaticMesh* FRPGItemHelper::GetItemStaticMesh(const FName& InRowName)
{
    const FRPGItemInfo* ItemInfo = GetItemInfo(InRowName);
    check(ItemInfo);
    return ItemInfo->StaticMesh;
}

ERPGItemCategory FRPGItemHelper::GetItemCategory(const FName& InRowName)
{
    const FRPGItemInfo* ItemInfo = GetItemInfo(InRowName);
    return ItemInfo->ItemCategory;
}
