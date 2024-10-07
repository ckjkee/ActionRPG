// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/RPGExperienceComponent.h"
#include "Components/RPGAttributesComponent.h"
#include "Components/RPGHealthComponent.h"
#include "Components/RPGInteractComponent.h"
#include "Components/RPGResurrectComponent.h"
#include "Components/RPGCameraShakeSourceComponent.h"
#include "Interfaces/RPGInteract.h"

ARPGPlayerCharacter::ARPGPlayerCharacter() : Super()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    check(SpringArmComponent);
    SpringArmComponent->SetupAttachment(GetMesh());
    SpringArmComponent->TargetArmLength = 400.f;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    check(CameraComponent);
    CameraComponent->SetupAttachment(SpringArmComponent);

    InteractComponent = CreateDefaultSubobject<URPGInteractComponent>(TEXT("InteractComponent"));
    check(InteractComponent);
    InteractComponent->OnLeftEvent.AddUObject(this, &ThisClass::OnLeftInteractingActor);
    InteractComponent->OnEnteredEvent.AddUObject(this, &ThisClass::OnEnteredInteractingActor);

    ResurrectComponent = CreateDefaultSubobject<URPGResurrectComponent>(TEXT("ResurrectionComponent"));

    CameraShakeSourceComponent = CreateDefaultSubobject<URPGCameraShakeSourceComponent>(TEXT("CameraShakeSourceComponent"));
    CameraShakeSourceComponent->SetupAttachment(GetRootComponent());
}

void ARPGPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    check(InteractComponent);
    InteractComponent->Start(SpringArmComponent);
}

void ARPGPlayerCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (this->GetVelocity().Size() == 0.f)
    {
        this->bUseControllerRotationYaw = false;
    }
    else
    {
        this->bUseControllerRotationYaw = true;
    }
}

void ARPGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveFB", this, &ThisClass::MoveForwardBackward);
    PlayerInputComponent->BindAxis("MoveLR", this, &ThisClass::MoveLeftRight);
    PlayerInputComponent->BindAxis("LookUD", this, &ThisClass::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookLR", this, &ThisClass::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ThisClass::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ThisClass::StopJumping);
    PlayerInputComponent->BindAxis("ZoomCamera", this, &ThisClass::ZoomCamera);
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ThisClass::Interact);
}

void ARPGPlayerCharacter::OnLeftInteractingActor(AActor* InActor)
{
    if (InActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnLeft = %s"), *InActor->GetName()); // TODO DELETE
    }
}

void ARPGPlayerCharacter::OnEnteredInteractingActor(AActor* InActor)
{
    if (InActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnEntered = %s"), *InActor->GetName()); // TODO DELETE
    }
}

void ARPGPlayerCharacter::MoveForwardBackward(const float Value)
{
    Move(EAxis::X, Value);
}

void ARPGPlayerCharacter::MoveLeftRight(const float Value)
{
    Move(EAxis::Y, Value);
}

void ARPGPlayerCharacter::Move(const EAxis::Type& axis, const float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        check(Controller);
        const FRotator Rotator = Controller->GetControlRotation();
        const FRotator YawRotator(0, Rotator.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(axis);
        AddMovementInput(Direction, Value);
    }
}

void ARPGPlayerCharacter::ZoomCamera(const float Value)
{
    if (Value == 0.f || !Controller) return;
    const float NewTargetArmLength = SpringArmComponent->TargetArmLength + Value * ZoomStep;
    SpringArmComponent->TargetArmLength = FMath::Clamp(NewTargetArmLength, MinTargetArmLength, MaxTargetArmLength);
}

void ARPGPlayerCharacter::Interact()
{
    check(InteractComponent);
    IRPGInteract* InteractActor = Cast<IRPGInteract>(InteractComponent->GetInteractingActor());
    if (InteractActor)
    {
        InteractActor->Interact(this);
    }
}
