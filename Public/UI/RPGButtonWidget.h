// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "Components/Button.h"
#include "RPGButtonWidget.generated.h"

class UTextBlock;
class FOnButtonClickedEvent;

UCLASS(Abstract)
class ACTIONRPG_API URPGButtonWidget final : public URPGBaseWidget
{
    GENERATED_BODY()
public:
    FOnButtonClickedEvent& OnButtonClicked() const;

protected:
    virtual void NativePreConstruct() override;

    UPROPERTY(EditAnywhere, Category = "Settings")
    FText ButtonText;

    UPROPERTY(meta = (BindWidget))
    UButton* Button;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextBlock;
};
