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
    UpdateMyWidget();
}

void URPGInteractWidgetComponent::SetObjectName(const FText& InObjectName)
{
    ObjectName = InObjectName;
    UpdateMyWidget();
}

void URPGInteractWidgetComponent::UpdateMyWidget() const
{
    IRPGWidgetInterface* InteractWidget = Cast<IRPGWidgetInterface>(GetWidget());
    check(InteractWidget);
    InteractWidget->SetInteractText(InteractText);
    InteractWidget->SetObjectName(ObjectName);
}
