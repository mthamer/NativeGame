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
private:
	GameObject mGo;
	PlayerShip mPlayerShip;
	String mBGSpritePath = { "background600x1024" };
	Sprite mBGSprite;		// background sprite

public:
	// singleton
	static Game *GetInstance() 
	{
		static Game theInstance;
		return &theInstance;
	}

	static String GetName() { return String("GameObject"); }

	Game() {}
	int Init();
	PlayerShip &GetPlayerShip() { return mPlayerShip;  }
	void Update(Single deltaTime);
};