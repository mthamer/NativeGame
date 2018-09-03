//
// Main game class
//

#pragma once

#include "Bindings.h"
#include "GameScript.h"
#include "PlayerShip.h"
#include "GameEntity.h"
#include <vector>

//
// main game class
//
class Rock;
class Explosion;
class Game : public GameEntity
{
private:
	PlayerShip mPlayerShip;
	Sprite mBGSprite;		// background sprite
	std::vector<Rock *> mRocks;
	std::vector<Explosion *> mExplosions;
	int mLastRockTime;
	int mLastUpdateTime;
	float mDeltaTime;

	void UpdateRocks(float deltaTime);
	void UpdateExplosions(float deltaTime);

public:
	// singleton
	static Game *GetInstance() 
	{
		static Game theInstance;
		return &theInstance;
	}

	static String GetName() { return String("GameObject"); }

	Game() {}
	virtual ~Game() {}

	int Init();
	PlayerShip &GetPlayerShip() { return mPlayerShip;  }
	void Update(float deltaTime);
	bool RemoveRock(Rock *rock);
	bool RemoveExplosion(Explosion *explo);
	int AddExplosion(Vector3 &pos);
	float GetDeltaTime() const { return mDeltaTime;  }
	const std::vector<Rock *> &GetRocks() const { return mRocks; }
	const std::vector<Explosion *> &GetExplosions() const { return mExplosions; }
};