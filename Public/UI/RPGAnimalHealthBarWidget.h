// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGAnimalHealthBarWidget.generated.h"

class IRPGHealth;
class IRPGFocus;
class UProgressBar;

UCLASS(Abstract)
class ACTIONRPG_API URPGAnimalHealthBarWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void UpdateWidget(const float InHealth);
protected:
	virtual void NativePreConstruct() override;
private:
    UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	IRPGHealth* HealthComponent;

	IRPGFocus* InteractComponent;

	void IsInFocus(AActor* Actor);
	void IsOutOfFocus(AActor* Actor);
};
