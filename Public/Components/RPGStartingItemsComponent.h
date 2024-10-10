// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGCurrentWeapon.h"
#include "RPGStartingItemsComponent.generated.h"

USTRUCT(BlueprintType)
struct FStartingItemInfo
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    FDataTableRowHandle ItemInfo;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0", ClampMax = "0", UIMax = "0"))
    float Probability = 1.f;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    uint32 Count = 1;
};

UCLASS()
class ACTIONRPG_API URPGStartingItemsComponent : public URPGBaseComponent
{
    GENERATED_BODY()
public:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TArray<FStartingItemInfo> Items;

    void AddStartingItems();
};
