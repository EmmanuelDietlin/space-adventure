// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceEntity.h"

// Sets default values
ASpaceEntity::ASpaceEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceEntity::BeginPlay()
{
	Super::BeginPlay();
	HeadComponent = Cast<UStaticMeshComponent>(GetDefaultSubobjectByName(TEXT("Head")));
	if (HeadComponent == nullptr) {
		UE_LOG(LogInit, Warning, TEXT("Could not find Head in SpaceEntity"));
	}
	
}

// Called every frame
void ASpaceEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

