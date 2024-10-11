// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGInventoryMessageWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS(Abstract)
class ACTIONRPG_API URPGInventoryMessageWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void SetItemName(const FText& InItemName) const;
	void SetItemCount(const int32 InItemCount) const;
	void SetItemTotal(const uint32 InItemTotal) const;
protected:
	virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemNameTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemCountTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemTotalTextBlock;

	UPROPERTY(meta = (BindWidget))
	UImage* PlusImage;

	UPROPERTY(meta = (BindWidget))
	UImage* MinusImage;

private:
	FTimerHandle TimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	float DelayBeforeRemove = 3.f;

	void SetType(const bool bIsAdded) const;
};
