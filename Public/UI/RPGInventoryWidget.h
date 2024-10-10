// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGInventoryWidget.generated.h"

class UPanelWidget;
class URPGInventorySlotWidget;
class IRPGInventory;

UCLASS(Abstract)
class ACTIONRPG_API URPGInventoryWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void SetInventory(IRPGInventory* OtherInventory);
protected:
    UPROPERTY(meta = (BindWidget))
	UPanelWidget* PanelWidget;

	virtual void Update() override;
private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<URPGInventorySlotWidget> SlotWidget;

	void InventorySlotClicked(const FName& RowName);

	bool IsEquiped(const FName& RowName);

	IRPGInventory* InventoryComponent;
};
