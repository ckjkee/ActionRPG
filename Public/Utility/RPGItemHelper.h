// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/CoreTypes/RPGTypes.h"

class UDataTable;
struct FRPGItemInfo;


class ACTIONRPG_API FRPGItemHelper final
{
public:
	static const UDataTable* GetDataTable();
	static const FRPGItemInfo* GetItemInfo(const FName& InRowName);
	static FText GetItemName(const FName& InRowName);
	static UStaticMesh* GetItemStaticMesh(const FName& InRowName);
	static ERPGItemCategory GetItemCategory(const FName& InRowName);
	static float GetItemDamage(const FName& InRowName);
	static USkeletalMesh* GetItemSkeletalMesh(const FName& InRowName);
	static TSubclassOf<UAnimInstance> GetItemAnimInstance(const FName& InRowName);
};
