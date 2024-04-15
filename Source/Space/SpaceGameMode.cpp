// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceGameMode.h"
#include "SpaceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpaceGameMode::ASpaceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
