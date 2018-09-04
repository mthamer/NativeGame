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
class Alien;
class Game : public GameEntity
{
private:
	PlayerShip mPlayerShip;
	Sprite mBGSprite;		// background sprite
	std::vector<Rock *> mRocks;
	std::vector<Explosion *> mExplosions;
	Alien *mAlien;
	int mLastRockTime;
	int mLastUpdateTime;
	int mLastAlienTime;
	float mDeltaTime;

	void CheckToAddAlien();
	int AddAlien();
	void UpdateRocks(float deltaTime);
	void UpdateExplosions(float deltaTime);
	void UpdateAlien(float deltaTime);

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
	void RemoveAlien();
	int AddExplosion(Vector3 &pos);
	float GetDeltaTime() const { return mDeltaTime;  }
	const std::vector<Rock *> &GetRocks() const { return mRocks; }
	const std::vector<Explosion *> &GetExplosions() const { return mExplosions; }
	Alien *GetAlien() { return mAlien;  }
};