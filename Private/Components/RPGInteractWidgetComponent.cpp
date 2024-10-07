// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGInteractWidgetComponent.h"
#include "Interfaces/RPGWidgetInterface.h"

URPGInteractWidgetComponent::URPGInteractWidgetComponent() : Super()
{
    SetWidgetSpace(EWidgetSpace::Screen);
    SetDrawAtDesiredSize(true);
    SetVisibility(false);
}

void URPGInteractWidgetComponent::BeginPlay()
{
    Super::BeginPlay();
    UpdateWidget();
}

void URPGInteractWidgetComponent::SetObjectName(const FText& InObjectName)
{
    ObjectName = InObjectName;
    UpdateWidget();
}

void URPGInteractWidgetComponent::UpdateWidget()
{
    IRPGWidgetInterface* InteractWidget = Cast<IRPGWidgetInterface>(GetWidget());
    if (InteractWidget)
    {
        InteractWidget->SetInteractText(InteractText);
        InteractWidget->SetObjectName(ObjectName);
    }
}
