// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "SpacePlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractDelegate);
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
	TSoftObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Properties")
	float Speed = 10;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Properties")
	float InteractDistance = 200;

	UPROPERTY(BlueprintAssignable)
	FOnInteractDelegate OnInteract;

private:


#pragma endregion


#pragma region Methods
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	void Move(const FInputActionValue& value);

	void Interact(const FInputActionValue& value);

	void Jump(const FInputActionValue& value);

	void Look(const FInputActionValue& value);
#pragma endregion

	
};
