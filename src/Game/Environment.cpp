#include "Environment.h"
///////////////////////////////////////////////////////////////////////////////
// Filename: Environment.cpp
// Implements the food spawning and respawning functions 
///////////////////////////////////////////////////////////////////////////////

void Environment::SpawnInitialFood(std::vector<std::unique_ptr<Food>>& foodList)
{
	//lets make 20 initially
	for (int i = 0; i < 20; i++)
	{
		foodList.push_back(std::make_unique<Food>(rand() % 800, rand() % 600));
	}
}

void Environment::Update(std::vector<std::unique_ptr<Food>>& foodList)
{
	//at random change spawn new food but first use any eaten food to save memory 
	if (rand() % 200 == 0) {
		for (std::unique_ptr<Food>& food : foodList) {
			if (food -> IsEaten()) {
				food -> RespawnRandom(); 
				return; 
			}
		}

		foodList.push_back(std::make_unique<Food>(rand() % 800, rand() % 600));
		
	}
	
}
