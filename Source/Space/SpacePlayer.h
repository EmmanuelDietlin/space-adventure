// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceEntity.h"
#include "GameFramework/Character.h"
#include "SpacePlayer.generated.h"

UCLASS()
class SPACE_API ASpacePlayer : public ASpaceEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpacePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
