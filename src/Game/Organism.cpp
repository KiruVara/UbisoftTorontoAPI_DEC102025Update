///////////////////////////////////////////////////////////////////////////////
// Filename: Organism.cpp
// Implements the main organism function (wander, find food, hunger logic)
///////////////////////////////////////////////////////////////////////////////

#include "Organism.h"
#include "../ContestAPI/app.h"
#include <cmath>
#include "Constants.h"
#include <algorithm>


namespace SG = Settings::Gameplay; 
namespace SP = Settings::Physics; 

void Organism::InitRandom()
{
	x = rand() % Settings::Window::SCREEN_WIDTH; 
	y = rand() % Settings::Window::SCREEN_HEIGHT; 

	hunger = 50.0f; 
	speed = 1.0f; 

	dirX = 0.00f; 
	dirY = 0.0f; 

	currentState = State::Wandering; 
}

void Organism::Update(float deltaTime, std::vector<std::unique_ptr<Food>>& foodList)
{
	//Hunger increases over time 
	hunger += SG::HUNGER_TIME * deltaTime; 

	//decide what to do 
	Think(deltaTime); 

	switch (currentState) 
	{
		case State::FindingFood:
			FindFood(deltaTime, foodList);
			break;
		
		case State::Wandering:
			Wander(deltaTime); 
			break; 

		default:
			Wander(deltaTime);
	}
}

void Organism::Render()
{
	//draw them as circles 
	//Draw the orgasims  using triangle to a circle 
	const int sides = 24;
	const float radius = 8.0f; //adjust for smaller or bigger;
	//colour for white
	const float r = 1.0f, g = 1.0f, b = 1.0f;

	//now create the triangles in a hexagon form:
	for (int i = 0; i < sides; i++) {
		//for the angles we need 2pi (360)
		float angle1 = (2.0f * PI * i) / sides;
		float angle2 = (2.0f * PI * (i + 1)) / sides;

		//take the angles to make the corridinates of each triangle
		//point 1
		float x1 = x + cosf(angle1) * radius;
		float y1 = y + sinf(angle1) * radius;
		//point 2
		float x2 = x + cosf(angle2) * radius;
		float y2 = y + sinf(angle2) * radius;
		//point 3 is the center (same for all) 

		App::DrawTriangle(
			x, y, SP::Z_TRIANGLE, SP::W_TRIANGLE,
			x1, y1, SP::Z_TRIANGLE, SP::W_TRIANGLE,
			x2, y2, SP::Z_TRIANGLE, SP::W_TRIANGLE,
			r, g, b, 
			r, g, b,
			r, g, b,
			false //filled
		);		
	}

}

void Organism::Think(float deltaTime)
{
	//state machine
	//Wander
	//Find Food
	//Eat
	//Run Away 
	//Chase
	//Reproduce
	//Rest
	//Die

	if (hunger > Settings::Gameplay::HUNGER_BASE) {
		currentState = State::FindingFood;
	}
	else {
		currentState = State::Wandering;
	}

}

void Organism::Wander(float deltaTime)
{
	//allow the organism to move in any direction
	dirX = ((rand() % SG::WANDER_VAR) - SG::WANDER_MID) * SG::WANDER_POWER;
	dirY = ((rand() % SG::WANDER_VAR) - SG::WANDER_MID) * SG::WANDER_POWER;

	float length = sqrt(dirX * dirX + dirY * dirY);
	//if the direction is too big divide by length so that the movement is small 
	if (length > 0.01f) {
		dirX /= length; 
		dirY /= length; 
	}
	x += dirX * speed; 
	y += dirY * speed; 

}

void Organism::FindFood(float deltaTime, std::vector<std::unique_ptr<Food>>& foodList)
{
	//loop through list to see if any food is available 
	for (std::unique_ptr<Food>& food : foodList) {
		//if that food is eaten skip over it and go to the next 
		if (food->IsEaten()) continue; 

		//find how far away the food is 
		float dx = food->GetX() - x;
		float dy = food->GetY() - y;

		//calculate distance (pythagoream) 
		float dist = sqrt(dx * dx + dy * dy);

		//If close enough organism should move towards it 
		if (dist < SG::VISISON_RADIUS)
		{
			//create direction vectors and have it move towards food
			dirX = dx / dist;
			dirY = dy / dist;

			x += dirX * speed;
			y += dirY * speed;

			//Eat if close enough 
			if (dist < SG::EAT_RADIUS)
			{
				food->Eat();
				hunger -= 20.0f; //hardcode for now -> change to variable depending on food type
			}
			return;
		}
	}
	//if there no food within sight go back to wandering 
	Wander(deltaTime); 

}
