// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGComponents.h"
#include "RPGExperienceComponent.generated.h"

UCLASS()
class ACTIONRPG_API URPGExperienceComponent final : public URPGBaseComponent, public IRPGComponents
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    FOnReachNewLevel OnReachNewLevelEvent;

    int16 inline GetCurrentLevel() const;
    UFUNCTION(BlueprintCallable)
    void AddExperience(const int32 Amount);

    void DecreaseExperience(const int32 Amount);

    virtual inline FOnReachNewLevel& OnReachNewLevel() override;

private:
    void SetNewTreshold(int32& Threshold, int16 level);

    void ManageExperience(const int32 Amount);

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "0"))
    int32 PlayerExperience = 0;

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "1"))
    int16 PlayerLevel = 1;

    int32 LevelTreshold = 1000;
    int32 PrevThreshold = 0;

    bool bHasDied = false;
};
