// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGExperienceComponent.h"

inline uint16 URPGExperienceComponent::GetCurrentLevel() const
{
    return PlayerLevel;
}

void URPGExperienceComponent::AddExperience(const uint32 Amount)
{
    PlayerExperience += Amount;
    if (PlayerExperience >= LevelTreshold)
    {
        PlayerLevel += 1;
        PlayerExperience -= LevelTreshold;
        OnReachNewLevel.Broadcast(PlayerLevel);
        SetNewLevelTreshold();
    }
}

void URPGExperienceComponent::DecreaseExperience(const uint32 Amount)
{
}

void URPGExperienceComponent::SetNewLevelTreshold()
{
    uint16 N = 0;
    for (uint16 i = 1; i <= PlayerLevel; ++i)
    {
        N = N + i;
    }
    LevelTreshold = 1000 * N;
}
