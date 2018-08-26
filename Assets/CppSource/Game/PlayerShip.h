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

	void FireMissile();
	void UpdateMissiles(Single deltaTime);

public:
	static String GetName() { return String("PlayerShip"); }

	PlayerShip() {}
	virtual ~PlayerShip() {}

	int Init();
	void SetPosition(Vector3 &pos);
	void Update(float deltaTime);
	void SetSpeed(float s) { mSpeed = s; }
	float GetSpeed() { return mSpeed; }
	bool RemoveMissile(Missile *missile);

	// TODO- get these from the actual sprite at runtime
	virtual float GetWidth() { return 39; }
	virtual float GetHeight() { return 43; }
};