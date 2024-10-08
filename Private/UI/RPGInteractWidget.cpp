// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "UI/RPGInteractWidget.h"
#include "Components/TextBlock.h"
#include "Utility/RPGHelperFunctions.h"

void URPGInteractWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if(ActionNameTextBlock)
    {
		ActionNameTextBlock->SetText(RPGHelperFunctions::GetDisplayNameByActionName(ActionName));
    }
}

void URPGInteractWidget::SetObjectName(const FText& ObjectName) const
{
	check(ObjectNameTextBlock);
	ObjectNameTextBlock->SetText(ObjectName);
}

void URPGInteractWidget::SetInteractText(const FText& InteractText) const
{
	check(InteractTextBlock);
	InteractTextBlock->SetText(InteractText);
}


