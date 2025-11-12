// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "01_Fundamentals/Core/Base/Character/GasCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGasCharacterBase::AGasCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Disable rotation with controller input for a typical third-person character set up
	// The character's orientation is usually controlled by movement input rather than direct controller rotation.
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationYaw = false;
	this->bUseControllerRotationRoll = false;

	// Configure character movement to orient rotation to movement direction
	const TObjectPtr<UCharacterMovementComponent> MovementComponent = this->GetCharacterMovement();
	MovementComponent->bOrientRotationToMovement = true;

	// Create and configure the Spring Arm Component for the camera
	this->CameraArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	this->CameraArmComponent->SetupAttachment(this->RootComponent.Get());
	this->CameraArmComponent->TargetArmLength = 400.0f; // The camera follows at this distance behind the character
	this->CameraArmComponent->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create and configure the Camera Component
	this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	this->CameraComponent->SetupAttachment(this->CameraArmComponent.Get(), USpringArmComponent::SocketName);
	this->CameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm	
}

// Handle look input
void AGasCharacterBase::Look(const FVector2d LookAxisVector)
{
	// Add yaw and pitch input to the current character's controller
	this->AddControllerYawInput(LookAxisVector.X);
	this->AddControllerPitchInput(LookAxisVector.Y);
}

// Handle move input
void AGasCharacterBase::Move(const FVector2d MovementVector)
{
	// Get the control rotation and isolate the yaw component
	const FRotator Rotation = this->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get the forward and right vectors based on the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Add movement input in the forward and right directions
	this->AddMovementInput(ForwardDirection, MovementVector.Y);
	this->AddMovementInput(RightDirection, MovementVector.X);
}
