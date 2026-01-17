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
		//hunger
		inline constexpr float METABOLISM = 0.01f; 
		inline constexpr int HUNGER_THRESHOLD = 60; 
		inline constexpr int EAT_RADIUS = 5;

		//rest
		inline constexpr int REST_THRESHOLD = 20; //if hunger is lower than rest threshold organism can rest
		inline constexpr int REST_MAX = 20; //amount of time organism can rest for

		//wander
		inline constexpr float WANDER_POWER = 0.0001f; //force of turn
		inline constexpr int WANDER_VAR = 200; //angles of turn
		inline constexpr int WANDER_MID = 100; //make sure it can turn in all directions 
		inline constexpr int WANDER_SPEED = 5; //divide speed by this to get a slower wander speed

		//sight
		inline constexpr int VISISON_RADIUS = 100;

		//age + repoduction
		inline constexpr float MAX_AGE = 60.0f; 


	}

	//Physics 
	namespace Physics {
		//2D so z and w are 0 
		inline constexpr int Z_TRIANGLE = 0; 
		inline constexpr int W_TRIANGLE = 1;


	}

}
