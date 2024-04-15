// Fill out your copyright notice in the Description page of Project Settings.

#include "SpacePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SpacePlayer.h"

void ASpacePlayerController::BeginPlay() 
{
	Super::BeginPlay();
}

void ASpacePlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ASpacePlayerController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	UEnhancedInputLocalPlayerSubsystem* InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!MappingContext.IsNull()) {
		InputSystem->AddMappingContext(MappingContext.LoadSynchronous(), 0);
	}

	Input->BindAction(InteractAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &ASpacePlayerController::Interact);
	Input->BindAction(MovementAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &ASpacePlayerController::Move);
}

void ASpacePlayerController::Move(const FInputActionValue& a_value) 
{
	FVector2D movement = a_value.Get<FVector2D>();
	ASpacePlayer* player = Cast<ASpacePlayer>(GetPawn());

	FVector direction = player->GetActorForwardVector() * movement.X;
	direction += player->GetActorRightVector() * movement.Y;
	direction.Normalize();
	float value = FMath::Sqrt(movement.X * movement.X + movement.Y * movement.Y) * Speed;

	player->AddMovementInput(direction, value);

	UE_LOG(LogTemp, Log, TEXT("Moved with vector %f : %f and force %f"), direction.X, direction.Y, value);
}

void ASpacePlayerController::Interact(const FInputActionValue& a_value) 
{
	UE_LOG(LogTemp, Log, TEXT("Interacted with object"));
}