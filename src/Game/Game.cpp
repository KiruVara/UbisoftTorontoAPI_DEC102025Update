///////////////////////////////////////////////////////////////////////////////
// Filename: Game.cpp
// Runs the game with all elements 
///////////////////////////////////////////////////////////////////////////////

#include "World.h"

World world; 

void Init()
{
	world.Init();

}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime)
{
	world.Update(deltaTime);
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{
	world.Render();

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
	world.Shutdown();
}