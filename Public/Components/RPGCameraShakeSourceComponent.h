// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Interfaces/RPGCameraShake.h"
#include "RPGCameraShakeSourceComponent.generated.h"

class IRPGHealth;

UCLASS()
class ACTIONRPG_API URPGCameraShakeSourceComponent : public UCameraShakeSourceComponent, public IRPGCameraShake
{
	GENERATED_BODY()
public:
    virtual void BeginPlay() override;

    virtual void StartShaking() override;
    virtual void StopShaking() override;

private:
    IRPGHealth* HealthComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Camera | Shaking", meta = (ClampMin = "0", UIMin = "0", ClampMax = "1", UIMax = "1"))
    float Scale = 0.5f;

};
