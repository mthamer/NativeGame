#pragma once

//
// Represents the player's ship on screen
//

#include "Bindings.h"
#include "GameEntity.h"
#include <vector>

class Missile;
class PlayerShip : public GameEntity
{
private:
	float mSpeed;
	float mTimeBetweenShots;
	int mLastShotTime;	// in ms
	
	// player ship sprite
	Sprite mSpriteLeft;		// for turning left
	Sprite mSpriteRight;	// for turning right
	Sprite mSpriteCenter;	// for going straight

	std::vector<Missile*> mMissiles;
	AudioClip mFireSound;
	AudioClip mPlayerExplosionSound;
	AudioClip mRockExplosionSound;

	void FireMissile();
	void UpdateMissiles(float deltaTime);
	void CheckRockCollision();

public:
	static String GetName() { return String("PlayerShip"); }

	PlayerShip() {}
	virtual ~PlayerShip() {}

	int Init();
	void Update(float deltaTime);
	void SetSpeed(float s) { mSpeed = s; }
	float GetSpeed() { return mSpeed; }
	bool RemoveMissile(Missile *missile);
};