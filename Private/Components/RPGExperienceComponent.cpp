// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/RPGExperienceComponent.h"
#include "Components/RPGHealthComponent.h"
#include "Utility/RPGHelperFunctions.h"

void URPGExperienceComponent::BeginPlay()
{
    Super::BeginPlay();
    OnReachNewLevelEvent.Broadcast(CharacterLevel);
    SetNewTreshold(LevelTreshold, CharacterLevel);
    SetNewTreshold(PrevThreshold, CharacterLevel - 1);

    HealthComponent = RPGHelperFunctions::GetComponentByInterface<IRPGHealth>(GetOwner());
    check(HealthComponent);
    HealthComponent->OnDead().AddUObject(this, &ThisClass::OnDeadApplyPenalty);
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

void URPGExperienceComponent::SetNewTreshold(int32& Threshold, const uint16 level)
{
    uint16 N = 0;
    for (uint16 i = 1; i <= level; ++i)
    {
        N = N + i;
    }
    Threshold = 1000 * N;
}

void URPGExperienceComponent::ManageExperience(const int32 Amount)
{
    if(bHasDied && CharacterLevel == 1 && CharacterExperience == 0)
    {
        bHasDied = false;
        return;
    }
    CharacterExperience = CharacterExperience + Amount;
    UE_LOG(LogTemp, Warning, TEXT("Experience = %d"), CharacterExperience); // TODO DELETE
    if (CharacterExperience >= LevelTreshold)
    {
        CharacterLevel += 1;
        UE_LOG(LogTemp, Warning, TEXT("Level =  %d"), CharacterLevel); // TODO DELETE
        OnReachNewLevelEvent.Broadcast(CharacterLevel);
        CharacterExperience -= LevelTreshold;
        PrevThreshold = LevelTreshold;
        SetNewTreshold(LevelTreshold, CharacterLevel);
    }
    if (bHasDied)
    {
        if (CharacterExperience <= 0)
        {
            if(CharacterLevel == 1)
            {
                bHasDied = false;
                return;
            }
            CharacterLevel -= 1;
            OnReachNewLevelEvent.Broadcast(CharacterLevel);
            CharacterExperience += PrevThreshold;
            LevelTreshold = PrevThreshold;
            SetNewTreshold(PrevThreshold, CharacterLevel - 1);
        }
        
        bHasDied = false;
    }
}

void URPGExperienceComponent::OnDeadApplyPenalty()
{
    bHasDied = true;
    DecreaseExperience(DeathExperiencePenalty);
}

void URPGExperienceComponent::DecreaseExperience(const int32 Amount)
{
    ManageExperience(-Amount);
}
