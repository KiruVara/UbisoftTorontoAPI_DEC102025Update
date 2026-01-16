///////////////////////////////////////////////////////////////////////////////
// Filename: LivingCreature.h
// Abstract class for living creatures that use think (behaviour function)
// Inherits from WorldObject.h
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "WorldObject.h"

class LivingCreature : public WorldObject {
public: 
	virtual ~LivingCreature() = default; 

	//Think function is where the living creature decides what to do 
	virtual void Think(float deltaTime) = 0; 

};