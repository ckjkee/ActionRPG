// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "Interfaces/RPGWidgetInterface.h"
#include "RPGInteractWidget.generated.h"

class UTextBlock;

UCLASS(Abstract)
class ACTIONRPG_API URPGInteractWidget final : public URPGBaseWidget, public IRPGWidgetInterface
{
	GENERATED_BODY()
public:
	virtual void SetObjectName(const FText& ObjectName) const override;
	virtual void SetInteractText(const FText& InteractText) const override;

protected:
	virtual void NativePreConstruct() override;

    UPROPERTY(meta = (BindWidget))
	UTextBlock* ActionNameTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InteractTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ObjectNameTextBlock;

private:
	UPROPERTY(EditDefaultsOnly)
	FName ActionName;
};
