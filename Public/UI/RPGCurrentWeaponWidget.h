// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGCurrentWeaponWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS(Abstract)
class ACTIONRPG_API URPGCurrentWeaponWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	void SetWeapon(const FName& InWeaponRow);

private:
    UPROPERTY(meta = (BindWidget))
	UTextBlock* DamageTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameTextBlock;

	UPROPERTY(meta = (BindWidget))
	UImage* Thumbnail;

	FName WeaponRowName;

	void UpdateThisWidget(FName& InNewWeapon);
};
