// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "RPGInteractWidgetComponent.generated.h"


UCLASS()
class ACTIONRPG_API URPGInteractWidgetComponent final : public UWidgetComponent
{
	GENERATED_BODY()
public:
	URPGInteractWidgetComponent();
	virtual void BeginPlay() override;
	void SetObjectName(const FText& InObjectName);
private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FText ObjectName;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FText InteractText;

	void UpdateWidget();
};
