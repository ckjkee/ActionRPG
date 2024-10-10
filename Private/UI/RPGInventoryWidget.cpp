// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "UI/RPGInventoryWidget.h"
#include "Components/PanelWidget.h"
#include "Interfaces/RPGInventory.h"
#include "UI/RPGInventorySlotWidget.h"

void URPGInventoryWidget::SetInventory(IRPGInventory* OtherInventory)
{
	check(OtherInventory);
	InventoryComponent = OtherInventory;
	InventoryComponent->OnInventoryChanged().AddUObject(this, &ThisClass::Update);
	Update();
}

void URPGInventoryWidget::Update()
{
	Super::Update();
	check(InventoryComponent);
	check(PanelWidget);

	PanelWidget->ClearChildren();
	const TMap<FName, uint32> Items = InventoryComponent->GetItems();
	for(const TPair<FName, uint32> Item : Items)
    {
		URPGInventorySlotWidget* InventorySlot = CreateWidget<URPGInventorySlotWidget>(this,SlotWidget);
		FRPGItemSlot ItemSlot{Item.Key, Item.Value,IsEquiped(Item.Key)};
		check(InventorySlot);
		InventorySlot->SetItem(ItemSlot);
		InventorySlot->OnInventorySlotButtonClickedEvent.AddUObject(this, &ThisClass::InventorySlotClicked);
		PanelWidget->AddChild(InventorySlot);
    }
}

void URPGInventoryWidget::InventorySlotClicked(const FName& RowName)
{
	UE_LOG(LogTemp, Warning, TEXT("SlotClicked")); // TODO: Delete after debug
}

bool URPGInventoryWidget::IsEquiped(const FName& RowName)
{
    return false;
}
