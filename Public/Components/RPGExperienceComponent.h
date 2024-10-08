// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGComponents.h"
#include "RPGExperienceComponent.generated.h"

class IRPGHealth;

UCLASS()
class ACTIONRPG_API URPGExperienceComponent final : public URPGBaseComponent, public IRPGComponents
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    FOnReachNewLevel OnReachNewLevelEvent;

    FOnExperienceChange OnExperienceChangeEvent;

    virtual uint16 GetCurrentLevel() override;

    UFUNCTION(BlueprintCallable) // TODO DELETE
    void AddExperience(const int32 Amount);

    UFUNCTION(BlueprintCallable) // TODO DELETE
    void DecreaseExperience(const int32 Amount);

    virtual FOnReachNewLevel& OnReachNewLevel() override;

    virtual FOnExperienceChange& OnExperienceChange() override;

    void SetLevel(uint16 InLevel);

    virtual int32 GetCurrentTreshold() const override;

    virtual int32 GetCurrentCharacterExperience() const override;

private:
    void SetNewTreshold(int32& Threshold, const uint16 level);

    void ManageExperience(const int32 Amount);

    void OnDeadApplyPenalty();

    UPROPERTY(EditDefaultsOnly, Category = "Level", meta = (ClampMin = "0"))
    int32 CharacterExperience = 0;

    UPROPERTY(EditAnywhere, Category = "Level", meta = (ClampMin = "1"))
    uint16 CharacterLevel = 1;

    UPROPERTY(EditAnywhere, Category = "Level", meta = (ClampMin = "1"))
    float DeathExperiencePenalty = 400.f;

    int32 LevelTreshold = 1000;
    int32 PrevThreshold = 0;

    bool bHasDied = false;

    IRPGHealth* HealthComponent;
};
