// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RPGTypes.generated.h"

UENUM(BlueprintType)
enum class ERPGItemCategory : uint8
{
    Other = 0       UMETA(DisplayName = "Other"), 
    Weapon          UMETA(DisplayName = "Weapon"),
    Utility         UMETA(DisplayName = "Utility")
};

USTRUCT(BlueprintType)
struct FRPGItemInfo : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    FText Name;

    UPROPERTY(EditDefaultsOnly)
    ERPGItemCategory ItemCategory = ERPGItemCategory::Other;

    UPROPERTY(EditDefaultsOnly)
    UTexture2D* Thumbnail = nullptr;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh* StaticMesh = nullptr;

    UPROPERTY(EditDefaultsOnly)
    USkeletalMesh* SkeletalMesh = nullptr;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAnimInstance> AnimInstanceClass;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float Damage = 20.f;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float AttackSpeed = 1.f;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
    float price = 50.f;
};