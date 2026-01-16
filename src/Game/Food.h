///////////////////////////////////////////////////////////////////////////////
// Filename: Food.h
// Basic food object that the organisms eat 
// Inherits from WorldObjext.h
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "WorldObject.h"

class Food : public WorldObject {
public: 
	Food(float x, float y); 
	void Update(float deltaTime) override; 
	void Render() override; 
	void Eat(); 
	bool IsEaten() const { return eaten; }

	//reuse eaten food to save memory 
	void RespawnRandom(); 

private: 
	bool eaten = false; 
};