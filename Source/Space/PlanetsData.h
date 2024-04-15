// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlanetsData.generated.h"

UENUM(BlueprintType)
enum LocationType {
	Planet,
	Space
};

USTRUCT(BlueprintType)
struct FPlanet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Name")
	FName PlanetName = "";

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Properties")
	float Gravity = 9.81f;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Properties")
	FIntVector Position = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Properties")
	TEnumAsByte<LocationType> Type = LocationType::Planet;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Asset")
	TSoftObjectPtr<UWorld> Map = nullptr;

};

/**
 * 
 */
UCLASS()
class SPACE_API UPlanetsData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Planets")
	TArray<FPlanet> Planets;

	UPROPERTY(EditAnywhere, Category = "Space")
	TMap<uint16, TSoftObjectPtr<UWorld>> SpaceLocations;

public:
	UFUNCTION()
	FPlanet GetPlanetByName(const FName a_name);

	UFUNCTION()
	FPlanet GetPlanetByCoords(const FIntVector a_coords);
};


