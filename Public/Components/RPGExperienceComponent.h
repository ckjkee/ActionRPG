// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "RPGExperienceComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnReachNewLevel, int)

    UCLASS() 
    class ACTIONRPG_API URPGExperienceComponent final : public URPGBaseComponent
{
    GENERATED_BODY()
public:
    FOnReachNewLevel OnReachNewLevel;

    int16 inline GetCurrentLevel() const;

    void AddExperience(const int32 Amount);

    void DecreaseExperience(const int32 Amount);

private:
    void SetNewTreshold(int32 Threshold);

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "0"))
    int32 PlayerExperience = 0;

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "1"))
    int16 PlayerLevel = 1;

    int32 LevelTreshold = 1000;
    int32 PrevThreshold = 0;
};
