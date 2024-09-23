// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ACTIONRPG_API RPGHelperFunctions
{
public:
    template <class T>
    static T* GetComponentByInterface(const AActor* InActor)
    {
        if (InActor)
        {
            const TArray<UActorComponent*> ActorComponents =
                InActor->GetComponentsByInterface(T::UClassType::StaticClass());
            if (ActorComponents.Num() > 0)
            {
                return Cast<T>(ActorComponents[0]);
            }
            checkNoEntry();
        }
        return nullptr;
    }
};
