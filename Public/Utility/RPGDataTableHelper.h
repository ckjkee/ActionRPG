// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ACTIONRPG_API FRPGDataTableHelper final
{
public:
    template <class T>
    static T* FindRow(const UDataTable* DataTable, const FName& InRowName)
    {
        check(DataTable);
        return DataTable->FindRow<T>(InRowName, ContextString, true);
    }

    template <class T>
    static T* GetFirstRow(const UDataTable* DataTable)
    {
        check(DataTable);
        TArray<T*> Rows;
        DataTable->GetAllRows<T>(ContextString, Rows);
        check(Rows.Num() > 0);
        return Rows[0];
    }

    template <class T>
    static void GetAllRows(const UDataTable* DataTable, TArray<T*>& Rows)
    {
        check(DataTable);
        DataTable->GetAllRows<T>(ContextString, Rows);
    }

    static TArray<FName> GetRowNames(const UDataTable* DataTable);
    static bool RowExists(const UDataTable* DataTable, const FName& InRowName);

private:
    static inline const FString ContextString{TEXT("Data Table")};
};
