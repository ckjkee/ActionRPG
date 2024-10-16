// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Components/Equipment/RPGEquipmentComponent.h"
#include "Interfaces/RPGRowName.h"

void URPGEquipmentComponent::ToggleEquip(const FName& RowName)
{
    bool bNeedToEquip = !RowName.IsEqual(EquippedItemRowName);
    UnEquip();
    if (bNeedToEquip)
    {
        Equip(RowName);
    }
}

void URPGEquipmentComponent::Equip(const FName& RowName)
{
    check(GetWorld());
    EquippedActor = GetWorld()->SpawnActorDeferred<AActor>(EquippedActorClass, FTransform::Identity, GetOwner(), nullptr,
                                                           ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
    if (EquippedActor)
    {
        EquippedActor->FinishSpawning(FTransform::Identity);
        AttachActorToSocket();
        IRPGRowName* ItemRowName = Cast<IRPGRowName>(EquippedActor);
        check(ItemRowName);
        ItemRowName->SetRowName(RowName);
        EquippedItemRowName = RowName;
    }
}

void URPGEquipmentComponent::UnEquip()
{
    if (EquippedActor)
    {
        EquippedActor->Destroy();
    }
    EquippedItemRowName = NAME_None;
}

FName URPGEquipmentComponent::GetEquippedItemRowName() const
{
    return EquippedItemRowName;
}

void URPGEquipmentComponent::SetSocketToEquip(USceneComponent* InSocket)
{
    SocketToEquip = InSocket;
}

bool URPGEquipmentComponent::IsEquipped() const
{
    return !EquippedItemRowName.IsNone();
}

AActor* URPGEquipmentComponent::GetEquippedActor() const
{
    return EquippedActor;
}

void URPGEquipmentComponent::AttachActorToSocket(USceneComponent* InComponent) const
{
    if(EquippedActor)
    {
        EquippedActor->AttachToComponent(InComponent ? InComponent : SocketToEquip,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    }
}
