// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGLevelProgressWidget.generated.h"

class UProgressBar;
class UTextBlock;
class IRPGComponents;

UCLASS(Abstract)
class ACTIONRPG_API URPGLevelProgressWidget final : public URPGBaseWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* CurrentExperienceBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentExperienceTextBlock;

	void SetWidgetProperties();

private:
	IRPGComponents* ExpComponent;

	void UpdateExperienceBarAndText();

	FText MakeFormatText() const;
};
