// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetsData.h"

FPlanet UPlanetsData::GetPlanetByCoords(const FIntVector a_coords) 
{
	for (auto& planet : Planets) 
	{
		if (planet.Position == a_coords) {
			return planet;
		}
	}
	//Si on ne trouve pas de planète à ces coordonnées, on renvoie une des maps espace.
	FPlanet planet = FPlanet();
	planet.Type = LocationType::Space;
	for (auto& [dist, world] : SpaceLocations) {
		if (a_coords.X * a_coords.X + a_coords.Y * a_coords.Y + a_coords.Z * a_coords.Z < dist) {
			planet.Map = world;
		}
	}
	return planet;
}

FPlanet UPlanetsData::GetPlanetByName(const FName a_name) 
{
	for (auto& planet : Planets)
	{
		if (planet.PlanetName == a_name) {
			return planet;
		}
	}
	return FPlanet();
}

