///////////////////////////////////////////////////////////////////////////////
// Filename: Organism.h
// This will represent all basic organisms that the player interacts with
// Uses functions like hunger, wander, and find food
// inherits from LivingCreature.h
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LivingCreature.h"
#include "Food.h"
#include <vector>
#include <memory>

class Organism : public LivingCreature {
public:
	//give each organism a random position at start
	void InitRandom(); 

	//update hunger and movement 
	void Update(float deltaTime) override; 

	//render organisms as circles 
	void Render() override; 

	//logic for organism actions
	void Think(float deltaTime) override; 

private: 
	float hunger = 50.0f; //hunger starts at 50 and increases over time
	float speed = 1.0f; 

	//behviour functions 
	void Wander(float deltaTime); 
	void SeekFood(float deltaTime, std::vector<std::unique_ptr<Food>>& food); //uses smart pointer for memory management

};

