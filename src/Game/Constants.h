///////////////////////////////////////////////////////////////////////////////
// Filename: Constants.h
// Store all constants here 
///////////////////////////////////////////////////////////////////////////////

#pragma once

namespace Settings {
	//window settings 
	namespace Window {
		inline constexpr int SCREEN_WIDTH = 800;
		inline constexpr int SCREEN_HEIGHT = 600; 
	}

	//Organism constants
	namespace Gameplay {
		inline constexpr float HUNGER_TIME = 0.01f; 
		inline constexpr int HUNGER_BASE = 60; 
		inline constexpr float WANDER_POWER = 0.0001f; //force of turn
		inline constexpr int WANDER_VAR = 200; //angles of turn
		inline constexpr int WANDER_MID = 100; //make sure it can turn in all directions 
		inline constexpr int VISISON_RADIUS = 100;
		inline constexpr int EAT_RADIUS = 5;
	}

	//Physics 
	namespace Physics {
		//2D so z and w are 0 
		inline constexpr int Z_TRIANGLE = 0; 
		inline constexpr int W_TRIANGLE = 1;


	}

}
