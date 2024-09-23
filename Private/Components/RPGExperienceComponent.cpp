// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGExperienceComponent.h"

void URPGExperienceComponent::BeginPlay()
{
    Super::BeginPlay();
    OnReachNewLevelEvent.Broadcast(CharacterLevel);
    SetNewTreshold(LevelTreshold, CharacterLevel);
    SetNewTreshold(PrevThreshold, CharacterLevel - 1);
}

int16 URPGExperienceComponent::GetCurrentLevel() const
{
    return CharacterLevel;
}

FOnReachNewLevel& URPGExperienceComponent::OnReachNewLevel()
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

    CharacterExperience = CharacterExperience + Amount;
    if (CharacterExperience >= LevelTreshold)
    {
        CharacterLevel += 1;
        UE_LOG(LogTemp, Warning, TEXT("Level =  %d"), CharacterLevel);
        OnReachNewLevelEvent.Broadcast(CharacterLevel);
        CharacterExperience -= LevelTreshold;
        PrevThreshold = LevelTreshold;
        SetNewTreshold(LevelTreshold, CharacterLevel);
    }
    if (CharacterExperience <= 0 && bHasDied)
    {
        CharacterLevel -= 1;
        OnReachNewLevelEvent.Broadcast(CharacterLevel);
        CharacterExperience += PrevThreshold;
        LevelTreshold = PrevThreshold;
        SetNewTreshold(PrevThreshold, CharacterLevel - 1);
    }
}

void URPGExperienceComponent::DecreaseExperience(const int32 Amount)
{
    ManageExperience(-Amount);
}
