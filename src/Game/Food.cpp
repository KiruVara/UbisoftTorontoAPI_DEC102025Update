///////////////////////////////////////////////////////////////////////////////
// Filename: Food.cpp
// Food rendering and eaten state 
///////////////////////////////////////////////////////////////////////////////

#include "Food.h"
#include "../ContestAPI/app.h"
#include "Constants.h"

Food::Food(float startX, float startY)
{
	x = startX; 
	y = startY; 
	
}

void Food::Update(float deltaTime)
{

}

void Food::Render()
{
	if (!eaten){
		//draw small green X to represent food 
		App::DrawLine(x - 2, y - 2, x + 2, y + 2, 0, 1, 0);
		App::DrawLine(x - 2, y + 2, x + 2, y - 2, 0, 1, 0);

	}
}

void Food::Eat()
{
	eaten = true; 
}

void Food::RespawnRandom()
{
	// Move food to a new random location
	x = rand() % Settings::Window::SCREEN_WIDTH;
	y = rand() % Settings::Window::SCREEN_HEIGHT;

	eaten = false;

}
