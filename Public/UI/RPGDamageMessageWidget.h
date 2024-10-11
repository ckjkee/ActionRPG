// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGDamageMessageWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS(Abstract)
class ACTIONRPG_API URPGDamageMessageWidget final : public URPGBaseWidget
{
    GENERATED_BODY()
public:
    void SetDamageTakenNumbers(const float InNumbers) const;
    void SetDamageDealtNumbers(const float InNumbers) const;
protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UImage* HeartImage;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* DamageDealtNumbersTextBlock;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* DamageTakenNumbersTextBlock;

private:
    FTimerHandle TimerHandle;

    UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
    float DelayBeforeRemove = 3.f;

    void SetType(const bool bIsHealed) const;
};
