// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Bases/RPGBaseComponent.h"

FTimerManager& URPGBaseComponent::GetWorldTimerManager() const
{
    check(GetWorld());
    return GetWorld()->GetTimerManager();
}
