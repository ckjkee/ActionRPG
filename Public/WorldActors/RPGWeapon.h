// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldActors/RPGWorldObject.h"
#include "Interfaces/RPGRowName.h"
#include "RPGWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS(Abstract) 
class ACTIONRPG_API ARPGWeapon : public ARPGWorldObject, public IRPGRowName
{
	GENERATED_BODY()
public:
	ARPGWeapon();
	virtual void SetRowName(const FName& InRowName) override;
	virtual FName GetRowName() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComponent;
private:
	FName WeaponRowName;
};
