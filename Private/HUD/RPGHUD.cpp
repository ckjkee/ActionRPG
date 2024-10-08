// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "HUD/RPGHUD.h"
#include "Blueprint/UserWidget.h"

void ARPGHUD::BeginPlay()
{
    Super::BeginPlay();
    UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(),HUDWidgetClass);
    check(UserWidget);
    UserWidget->AddToViewport();
}
