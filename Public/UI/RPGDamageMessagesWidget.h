// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGDamageMessagesWidget.generated.h"

class UPanelWidget;
class URPGDamageMessageWidget;
class IRPGHealth;
class IRPGCurrentWeapon;

UCLASS(Abstract)
class ACTIONRPG_API URPGDamageMessagesWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	void SetPlayerHealthComponent(IRPGHealth* InHealth);
	void SetPlayerCurrentWeaponComponent(IRPGCurrentWeapon* InCurrentWeapon);
protected:
    UPROPERTY(meta = (BindWidget))
	UPanelWidget* PanelWidget;
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URPGDamageMessageWidget> DamageMessageClass;

	IRPGHealth* PlayerHealh;

	IRPGCurrentWeapon* PlayerCurrentWeapon;

	void OnDealDamage(const float InDamage);
	void OnDamageTaken(const float InDamage);
	void CreateDamageMessageWidget(const float InDamage);
};
