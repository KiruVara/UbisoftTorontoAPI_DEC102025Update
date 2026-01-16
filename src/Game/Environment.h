///////////////////////////////////////////////////////////////////////////////
// Filename: Environment.h
// Spawn and respawn food around the world 
// Will also deal with different terrains in the future 
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Food.h"
#include <vector>
#include <memory>

class Environment {
public:
	void SpawnInitialFood(std::vector<std::unique_ptr<Food>>& foodList); 
	void Update(std::vector<std::unique_ptr<Food>>& foodList); 

private:

};