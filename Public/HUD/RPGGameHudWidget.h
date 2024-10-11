// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/RPGHudWidget.h"
#include "RPGGameHudWidget.generated.h"

class URPGInventoryWidget;
class URPGCurrentWeaponWidget;
class URPGInventoryMessagesWidget;
class URPGDamageMessagesWidget;


UCLASS(Abstract)
class ACTIONRPG_API URPGGameHudWidget final : public URPGHudWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	URPGInventoryWidget* InventoryWidget;

	UPROPERTY(meta = (BindWidget))
	URPGCurrentWeaponWidget* CurrentWeaponWidget;

	UPROPERTY(meta = (BindWidget))
	URPGInventoryMessagesWidget* InventoryMessagesWidget;

	UPROPERTY(meta = (BindWidget))
	URPGDamageMessagesWidget* DamageMessagesWidget;
};
