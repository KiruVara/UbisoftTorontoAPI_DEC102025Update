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
#include "Constants.h"

namespace SG = Settings::Gameplay;

class Organism : public LivingCreature {
public:
	//state machine for organism 
	enum class State {
		Wandering, 
		FindingFood,
		Eating,
		RuningAway, //TBD
		Chasing,	//TBD
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
	float restTime = 0.0f;
	float age = 0.0f; 

	//traits 
	float speed = 1.0f;
	float visionRadius = SG::VISISON_RADIUS; 
	float metabolism = SG::METABOLISM; 
	float maxAge = SG::MAX_AGE; 

	//movement direction 
	float dirX = 0.0f; 
	float dirY = 0.0f; 

	State currentState = State::Wandering; 

	//behviour functions 
	void Wander(float deltaTime); 
	void FindFood(float deltaTime, std::vector<std::unique_ptr<Food>>& foodList); 
	void Rest(float deltaTime);
	void Eat();


};

