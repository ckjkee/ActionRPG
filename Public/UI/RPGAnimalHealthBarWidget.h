// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "Interfaces/RPGFocus.h"
#include "RPGAnimalHealthBarWidget.generated.h"

class UProgressBar;

UCLASS(Abstract)
class ACTIONRPG_API URPGAnimalHealthBarWidget final : public URPGBaseWidget, public IRPGFocus
{
	GENERATED_BODY()
public:
	virtual void UpdateProgressBar(const float CurrentHealth, const float MaxHealth) override;
protected:
	virtual void NativePreConstruct() override;
private:
    UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
};
