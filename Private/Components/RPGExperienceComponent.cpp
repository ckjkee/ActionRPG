// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGExperienceComponent.h"

inline int16 URPGExperienceComponent::GetCurrentLevel() const
{
    return PlayerLevel;
}

void URPGExperienceComponent::AddExperience(const int32 Amount)
{
    PlayerExperience += Amount;
    if (PlayerExperience >= LevelTreshold)
    {
        PlayerLevel += 1;
        OnReachNewLevel.Broadcast(PlayerLevel);
        PlayerExperience -= LevelTreshold;
        PrevThreshold = LevelTreshold;
        SetNewTreshold(LevelTreshold, PlayerLevel);
    }
}

void URPGExperienceComponent::SetNewTreshold(int32 Threshold, int16 level)
{
    int16 N = 0;
    for (int16 i = 1; i <= level; ++i)
    {
        N = N + i;
    }
    Threshold = 1000 * N;
}

void URPGExperienceComponent::DecreaseExperience(const int32 Amount)
{
    PlayerExperience -= Amount;
    if (PlayerExperience <= 0)
    {
        PlayerLevel -= 1;
        OnReachNewLevel.Broadcast(PlayerLevel);
        PlayerExperience += PrevThreshold;
        LevelTreshold = PrevThreshold;
        SetNewTreshold(PrevThreshold, PlayerLevel - 1);
    }
}
