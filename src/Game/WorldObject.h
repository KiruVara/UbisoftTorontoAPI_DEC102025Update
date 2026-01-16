///////////////////////////////////////////////////////////////////////////////
// Filename: WorldObject.h
// Base class for all objects that exist in world
// Provides a position for objects
// Abstract base class
///////////////////////////////////////////////////////////////////////////////

#pragma once

class WorldObject {
public:
	virtual ~WorldObject() = default; 

	virtual void Update(float deltaTime) = 0; 
	virtual void Render() = 0; 

	//position getters
	float GetX() const { return x; }
	float GetY() const { return y; }

protected:
	float x = 0.0f; 
	float y = 0.0f; 
};