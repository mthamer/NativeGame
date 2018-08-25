#pragma once

//
// Represents the player's ship on screen
//

#include "Bindings.h"
#include <vector>

using namespace System;
using namespace UnityEngine;

class Missile;
class PlayerShip
{
private:
	GameObject mGo;
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

	int Init();
	void SetPosition(Vector3 &pos);
	void Update(Single deltaTime);
	void SetSpeed(float s) { mSpeed = s; }
	float GetSpeed() { return mSpeed; }
	bool RemoveMissile(Missile *missile);
};