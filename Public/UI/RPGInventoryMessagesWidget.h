// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGInventoryMessagesWidget.generated.h"

class URPGInventoryMessageWidget;
class IRPGInventory;
class UPanelWidget;

UCLASS(Abstract)
class ACTIONRPG_API URPGInventoryMessagesWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void SetInventory(IRPGInventory* InInventory);
protected:

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* PanelWidget;

private:
	void OnAddItem(const FName& InName, const uint32 InCount);
	void OnRemoveItem(const FName& InName, const uint32 InCount);
	void CreateInventoryMessageWidget(const FName& InName, const int InCount);

	IRPGInventory* Inventory;

    UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URPGInventoryMessageWidget> MessageWidgetClass;

	
};
