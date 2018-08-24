//
// Main game class
//

#pragma once

#include "Bindings.h"
#include "GameScript.h"
#include "PlayerShip.h"

namespace
{
	struct GameState
	{
		float data;
	};

	GameState* gameState;
}

//
// main game class
//
class Game
{
//	friend struct MyGame::GameScript;
private:
	GameObject mGo;
	PlayerShip mPlayerShip;

public:
	// singleton
	static Game *GetInstance() 
	{
		static Game *theInstance = nullptr;
		if (theInstance == nullptr)
			theInstance = new Game;
		return theInstance;
	}

	static String GetName() { return String("GameObject"); }
	static void Update(Single deltaTime, GameObject &gameOb, Transform &transform);

	Game() {}
	int Init();
	PlayerShip &GetPlayerShip() { return mPlayerShip;  }
};