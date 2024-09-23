// Copyright Stanislav Bezrukov. All Rights Reserved.

#pragma once

#include "Characters/RPGCharacter.h"
#include "CoreMinimal.h"
#include "Interfaces/RPGPlayerInfo.h"
#include "RPGPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URPGInteractComponent;
class URPGResurrectComponent;
class URPGCameraShakeSourceComponent;

UCLASS(Abstract)
class ACTIONRPG_API ARPGPlayerCharacter final : public ARPGCharacter, public IRPGPlayerInfo
{
    GENERATED_BODY()

public:
    ARPGPlayerCharacter();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGInteractComponent* InteractComponent;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGResurrectComponent* ResurrectComponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    URPGCameraShakeSourceComponent* CameraShakeSourceComponent;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Camera | Zoom", meta = (ClampMin = "0", UIMin = "0"))
    float MaxTargetArmLength = 600.f;

    UPROPERTY(EditDefaultsOnly, Category = "Camera | Zoom", meta = (ClampMin = "0", UIMin = "0"))
    float MinTargetArmLength = 150.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Camera | Zoom", meta = (ClampMin = "0", UIMin = "0"))
    float ZoomStep = 15.f;


    void OnLeftInteractingActor(AActor* InActor);
    void OnEnteredInteractingActor(AActor* InActor);
    void MoveForwardBackward(const float Value);
    void MoveLeftRight(const float Value);
    void Move(const EAxis::Type& axis, const float Value);
    void ZoomCamera(const float Value);
};
