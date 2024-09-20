// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "RPGExperienceComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewLevel, int)

    UCLASS() class ACTIONRPG_API URPGExperienceComponent final : public URPGBaseComponent
{
    GENERATED_BODY()
public:

    FOnNewLevel OnNewLevel;

    uint16 inline GetCurrentLevel() const;

    void AddExperience(uint32 Amount);

private:
    void SetNewLevelTreshold();

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "0"))
    uint32 PlayerExperience = 0;

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "1"))
    uint16 PlayerLevel = 1;

    uint32 LevelTreshold = 1000;
};
