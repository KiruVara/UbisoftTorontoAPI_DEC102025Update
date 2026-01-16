///////////////////////////////////////////////////////////////////////////////
// Filename: World.h
// Manages the game world elements 
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Organism.h"
#include "Food.h"
#include "Environment.h"
#include <vector>
#include <memory>

class World {
public:
	void Init(); 
	void Update(float deltaTime); 
	void Render(); 
	void Shutdown(); 

private:
	std::vector<std::unique_ptr<Organism>> organisms; 
	std::vector<std::unique_ptr<Food>> foodList;
	Environment environment;


};
