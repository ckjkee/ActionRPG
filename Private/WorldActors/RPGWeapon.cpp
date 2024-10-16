// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "WorldActors/RPGWeapon.h"
#include "Utility/RPGItemHelper.h"

ARPGWeapon::ARPGWeapon() : Super()
{
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	check(SkeletalMeshComponent);
	SetRootComponent(SkeletalMeshComponent);
	SetActorEnableCollision(false);
}

void ARPGWeapon::SetRowName(const FName& InRowName)
{
	check(SkeletalMeshComponent);
	WeaponRowName = InRowName;
	SkeletalMeshComponent->SetSkeletalMesh(FRPGItemHelper::GetItemSkeletalMesh(InRowName));
	//SkeletalMeshComponent->SetAnimInstanceClass(FRPGItemHelper::GetItemAnimInstance(InRowName)); Dont need for melee weapons
}

FName ARPGWeapon::GetRowName()
{
    return WeaponRowName;
}
