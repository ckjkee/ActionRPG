// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "RPGHealthWidgetComponent.generated.h"

class IRPGHealth;

UCLASS()
class ACTIONRPG_API URPGHealthWidgetComponent final : public UWidgetComponent
{
    GENERATED_BODY()
public:
    URPGHealthWidgetComponent();
    virtual void BeginPlay() override;

private:
    void UpdateProgressBar(const float InCurrentHealth);

    IRPGHealth* Health;
};
