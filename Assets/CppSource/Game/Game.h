//
// Main game class
//

#pragma once

#include "Bindings.h"
#include "PlayerShip.h"

//
// Interface to Main Unity game script
//
namespace MyGame
{
	struct GameScript : MyGame::BaseGameScript
	{
		MY_GAME_GAME_SCRIPT_DEFAULT_CONSTRUCTOR
		void Update() override;
	};
}

//
// main game class
//
class Game
{
	friend struct MyGame::GameScript;
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

	Game() {}
	static String GetName() { return String("GameObject"); }
	int Init();
};