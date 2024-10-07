// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGHealthWidget.generated.h"

class UProgressBar;
class IRPGHealth;

UCLASS(Abstract)
class ACTIONRPG_API URPGHealthWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void UpdateWidget(const float InHealth);
protected:
	virtual void NativePreConstruct() override;

    UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

private:
	IRPGHealth* HealthComponent;
};
