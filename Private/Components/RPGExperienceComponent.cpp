// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGExperienceComponent.h"

void URPGExperienceComponent::BeginPlay()
{
    Super::BeginPlay();
    OnReachNewLevelEvent.Broadcast(PlayerLevel);
    SetNewTreshold(LevelTreshold,PlayerLevel);
    SetNewTreshold(PrevThreshold, PlayerLevel - 1);
}

inline int16 URPGExperienceComponent::GetCurrentLevel() const
{
    return PlayerLevel;
}


inline FOnReachNewLevel& URPGExperienceComponent::OnReachNewLevel()
{
    return OnReachNewLevelEvent;
}


void URPGExperienceComponent::AddExperience(const int32 Amount)
{
    ManageExperience(Amount);
}

void URPGExperienceComponent::SetNewTreshold(int32& Threshold, int16 level)
{
    int16 N = 0;
    for (int16 i = 1; i <= level; ++i)
    {
        N = N + i;
    }
    Threshold = 1000 * N;
}

void URPGExperienceComponent::ManageExperience(const int32 Amount)
{

    PlayerExperience = PlayerExperience + Amount;
    if (PlayerExperience >= LevelTreshold)
    {
        PlayerLevel += 1;
        UE_LOG(LogTemp, Warning, TEXT("Level =  %d"), PlayerLevel);
        OnReachNewLevelEvent.Broadcast(PlayerLevel);
        PlayerExperience -= LevelTreshold;
        PrevThreshold = LevelTreshold;
        SetNewTreshold(LevelTreshold, PlayerLevel);
    }
    if (PlayerExperience <= 0 && bHasDied)
    {
        PlayerLevel -= 1;
        OnReachNewLevelEvent.Broadcast(PlayerLevel);
        PlayerExperience += PrevThreshold;
        LevelTreshold = PrevThreshold;
        SetNewTreshold(PrevThreshold, PlayerLevel - 1);
    }
}

void URPGExperienceComponent::DecreaseExperience(const int32 Amount)
{
    ManageExperience(-Amount);
}




