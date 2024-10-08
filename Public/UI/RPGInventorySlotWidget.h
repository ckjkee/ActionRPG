// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGInventorySlotWidget.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnInventorySlotButtonClicked, const FName&)

class UButton;
class UImage;
class UTextBlock;

struct FRPGItemSlot
{
    FName RowName;
    uint32 Count;
    bool bIsActive;
};

UCLASS()
class ACTIONRPG_API URPGInventorySlotWidget : public URPGBaseWidget
{
    GENERATED_BODY()
public:
    void SetItem(const FRPGItemSlot& InItemSlot);

    FOnInventorySlotButtonClicked OnInventorySlotButtonClickedEvent;
protected:
     virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UButton* SlotButton;

    UPROPERTY(meta = (BindWidget))
    UImage* Thumbnail;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemName;

    UFUNCTION(BlueprintPure)
    bool IsActive() const;

private:
    FRPGItemSlot ItemSlot;

    void OnSlotClicked();
    FText MakeValidName(const FText& InName) const;
};
