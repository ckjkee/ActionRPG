// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "WorldActors/RPGBorder.h"
#include "Components/BoxComponent.h"

ARPGBorder::ARPGBorder() : Super()
{
    ExternalBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("External Border"));
    check(ExternalBoxCollision);
    SetRootComponent(ExternalBoxCollision);
    ExternalBoxCollision->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnExternalBoxCollisionEndOverlap);

    InternalBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Internal Border"));
    check(InternalBoxCollision);
    InternalBoxCollision->SetupAttachment(ExternalBoxCollision);
    InternalBoxCollision->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnInternalBoxCollisionEndOverlap);
}

void ARPGBorder::OnExternalBoxCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (Player)
    {
       Player->SetActorLocation(Location); 
    }
}

void ARPGBorder::OnInternalBoxCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    check(OtherActor);
    Player = OtherActor;
    Location = OtherActor->GetActorLocation();
}
