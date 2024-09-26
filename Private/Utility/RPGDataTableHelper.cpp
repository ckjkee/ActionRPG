// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Utility/RPGDataTableHelper.h"
#include "Engine/DataTable.h"

TArray<FName> FRPGDataTableHelper::GetRowNames(const UDataTable* DataTable)
{
    check(DataTable);
    return DataTable->GetRowNames();
}

bool FRPGDataTableHelper::RowExists(const UDataTable* DataTable, const FName& InRowName)
{
    check(DataTable);
    return DataTable->GetRowNames().Contains(InRowName);
}
