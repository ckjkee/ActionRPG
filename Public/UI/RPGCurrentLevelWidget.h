// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGCurrentLevelWidget.generated.h"

class UTextBlock;

UCLASS(Abstract)
class ACTIONRPG_API URPGCurrentLevelWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentLevelTextBlock;

private:
	void UpdateCurrentLevel(const int16 InCurrentLevel) const;
};
