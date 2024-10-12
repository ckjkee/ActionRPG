// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RPGBaseWidget.h"
#include "RPGHudWidget.generated.h"

class URPGLoadingScreen;

UCLASS(Abstract)
class ACTIONRPG_API URPGHudWidget : public URPGBaseWidget
{
	GENERATED_BODY()
protected:
    UPROPERTY(meta = (BindWidget))
	URPGLoadingScreen* LoadingScreenWidget;

	virtual void NativeConstruct() override;
};
