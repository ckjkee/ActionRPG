// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bases/RPGBaseComponent.h"
#include "Interfaces/RPGEquipment.h"
#include "RPGEquipmentComponent.generated.h"


UCLASS(Abstract)
class ACTIONRPG_API URPGEquipmentComponent : public URPGBaseComponent, public IRPGEquipment
{
	GENERATED_BODY()
public:
	virtual void ToggleEquip(const FName& RowName) override;
	virtual FName GetEquippedItemRowName() const override;
	void SetSocketToEquip(USceneComponent* InSocket);
protected:
	virtual void Equip(const FName& RowName);
	virtual void UnEquip();
	void AttachActorToSocket(USceneComponent* InComponent = nullptr) const;
	bool IsEquipped() const;
	AActor* GetEquippedActor() const;
private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<AActor> EquippedActorClass;

	UPROPERTY()
	USceneComponent* SocketToEquip;

	UPROPERTY()
	AActor* EquippedActor;

	FName EquippedItemRowName;
};
