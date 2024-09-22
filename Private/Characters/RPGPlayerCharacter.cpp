// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "Characters/RPGPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/RPGExperienceComponent.h"
#include "Components/RPGAttributesComponent.h"
#include "Components/RPGHealthComponent.h"
#include "Components/RPGInteractComponent.h"

ARPGPlayerCharacter::ARPGPlayerCharacter() : Super()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    check(SpringArmComponent);
    SpringArmComponent->SetupAttachment(GetMesh());
    SpringArmComponent->TargetArmLength = 400.f;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    check(CameraComponent);
    CameraComponent->SetupAttachment(SpringArmComponent);

    ExperienceComponent = CreateDefaultSubobject<URPGExperienceComponent>(TEXT("ExperienceComponent"));

    check(ExperienceComponent);
    check(AttributesComponent);
    AttributesComponent->SetExperienceComponent(ExperienceComponent);

    check(HealthComponent);
    HealthComponent->SetAttributes(AttributesComponent);

    InteractComponent = CreateDefaultSubobject<URPGInteractComponent>(TEXT("InteractComponent"));
    check(InteractComponent);
    InteractComponent->OnLeftEvent.AddUObject(this, &ThisClass::OnLeftInteractingActor);
    InteractComponent->OnEnteredEvent.AddUObject(this, &ThisClass::OnEnteredInteractingActor);
}

void ARPGPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    check(InteractComponent);
    InteractComponent->Start(CameraComponent);
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
}

void ARPGPlayerCharacter::OnLeftInteractingActor(AActor* InActor)
{
    if (InActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnLeft = %s"), *InActor->GetName());
    }
}

void ARPGPlayerCharacter::OnEnteredInteractingActor(AActor* InActor)
{
    if (InActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnEntered = %s"), *InActor->GetName());
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
