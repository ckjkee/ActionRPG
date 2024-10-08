// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RPGHUD.generated.h"

UCLASS(Abstract)
class ACTIONRPG_API ARPGHUD final : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSubclassOf<UUserWidget> HUDWidgetClass;
};
