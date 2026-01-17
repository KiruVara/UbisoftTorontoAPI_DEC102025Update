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
	enum class State {
		Wandering, 
		FindingFood,
		Eating,
		RuningAway, 
		Chasing,
		Reproducing,
		Resting,
		Dying
	};
	//give each organism a random position at start
	void InitRandom(); 

	//base update
	void Update(float deltaTime) override {};

	//update hunger and movement overload 
	void Update(float deltaTime, std::vector<std::unique_ptr<Food>>& foodList);

	//render organisms as circles 
	void Render() override; 

	//logic for organism actions
	void Think(float deltaTime) override; 

private: 
	float hunger = 50.0f; //hunger starts at 50 and increases over time
	float speed = 1.0f; 

	//movement direction 
	float dirX = 0.0f; 
	float dirY = 0.0f; 

	State currentState = State::Wandering; 

	//behviour functions 
	void Wander(float deltaTime); 
	void FindFood(float deltaTime, std::vector<std::unique_ptr<Food>>& foodList); 

};

