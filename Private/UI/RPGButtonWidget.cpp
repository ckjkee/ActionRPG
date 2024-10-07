// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "UI/RPGButtonWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

FOnButtonClickedEvent& URPGButtonWidget::OnButtonClicked() const
{
    check(Button);
    return Button->OnClicked;
}

void URPGButtonWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
    if(TextBlock)
    {
        TextBlock->SetText(ButtonText);
    }
}
