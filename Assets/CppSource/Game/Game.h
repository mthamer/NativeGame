//
// Main game class
//

#pragma once

#include "Bindings.h"
#include "GameScript.h"
#include "PlayerShip.h"
#include <vector>

// unused
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
class Rock;
class Game
{
private:
	GameObject mGo;
	PlayerShip mPlayerShip;
	String mBGSpritePath = { "background600x1024" };
	Sprite mBGSprite;		// background sprite
	std::vector<Rock *> mRocks;
	int mLastRockTime;
	int mLastUpdateTime;
	float mDeltaTime;

	void UpdateRocks(Single deltaTime);

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
	bool RemoveRock(Rock *rock);
	float GetDeltaTime() const { return mDeltaTime;  }
};