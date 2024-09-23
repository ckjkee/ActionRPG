// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGAttributes.h"
#include "RPGAttributesComponent.generated.h"

class IRPGComponents;

UCLASS()
class ACTIONRPG_API URPGAttributesComponent final : public URPGBaseComponent, public IRPGAttributes
{
    GENERATED_BODY()
public:
    FOnAttributesChanged OnAttributesChangedEvent;

    virtual void BeginPlay() override;
    void SetNewAttributes(int16 CharacterLevel);
    virtual FOnAttributesChanged& OnAttributesChanged() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes", meta = (ClampMin = "0", UIMin = "0"))
    float BaseHealth = 100.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes", meta = (ClampMin = "0", UIMin = "0"))
    float BaseDamage = 20.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes", meta = (ClampMin = "0", UIMin = "0"))
    float BaseAttackSpeed = 0.5f;

private:
    float CurrentHealth = 0.f;
    float CurrentDamage = 0.f;
    float CurrentAttackSpeed = 0.f;

    IRPGComponents* ExperienceComponent;
    
};
