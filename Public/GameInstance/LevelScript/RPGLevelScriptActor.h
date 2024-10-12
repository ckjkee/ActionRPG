// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "RPGLevelScriptActor.generated.h"


UCLASS(Abstract)
class ACTIONRPG_API ARPGLevelScriptActor final : public ALevelScriptActor
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

private:
	void TestLoadingDelay() const;
};
