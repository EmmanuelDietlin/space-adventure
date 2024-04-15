// Fill out your copyright notice in the Description page of Project Settings.


#include "SpacePlayer.h"

// Sets default values
ASpacePlayer::ASpacePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpacePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpacePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpacePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

