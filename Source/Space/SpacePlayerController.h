// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "SpacePlayerController.generated.h"


/**
 * 
 */
UCLASS()
class SPACE_API ASpacePlayerController : public APlayerController
{
	GENERATED_BODY()

#pragma region Fields
public:
	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, Category = "Properties")
	float Speed = 10;

private:

#pragma endregion


#pragma region Methods
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	void Move(const FInputActionValue& value);

	void Interact(const FInputActionValue& value);
#pragma endregion

	
};
