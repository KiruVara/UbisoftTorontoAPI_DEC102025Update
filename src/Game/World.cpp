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

	//create organisms let's start with 15
	for (int i = 0; i < 15; i++) {
		std::unique_ptr<Organism> org = std::make_unique<Organism>(); 
		org->InitRandom(); 
		organisms.push_back(std::move(org)); 
	}
}

void World::Update(float deltaTime) {
	environment.Update(foodList); 

	for (std::unique_ptr<Organism>&org : organisms) {
		org->Update(deltaTime, foodList); 
	}
}

void World::Render() {
	for (std::unique_ptr<Food>& food : foodList) {
		food->Render(); 
	}

	for (std::unique_ptr<Organism>& org : organisms) {
		org->Render();
	}
}

void World::Shutdown()
{
	foodList.clear(); 
	organisms.clear(); 
}
