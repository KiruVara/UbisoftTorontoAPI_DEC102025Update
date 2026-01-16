///////////////////////////////////////////////////////////////////////////////
// Filename: World.cpp
// Creates the game world (init, update, render, shutdown) 
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <World.h>
#include "Food.h"



void World::Init() {
	//create initial food 
	environment.SpawnInitialFood(foodList); 
}

void World::Update(float deltaTime) {
	environment.Update(foodList); 
}

void World::Render() {
	for (std::unique_ptr<Food>& food : foodList) {
		food->Render(); 
	}
}

void World::Shutdown()
{
	foodList.clear(); 
}
