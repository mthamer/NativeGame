#pragma once

//
// Represents the player's ship on screen
//

#include "Bindings.h"

using namespace System;
using namespace UnityEngine;

class PlayerShip
{
private:
	GameObject mGo;

	// Path of sprites within the Unity Assets/Resources folder
	String mSpriteLeftPath = { "spaceship_high_left" };
	String mSpriteRightPath = { "spaceship_high_right" };
	String mSpriteCenterPath = { "spaceship_high_center" };

	// player ship sprite
	Sprite mSpriteLeft;		// for turning left
	Sprite mSpriteRight;	// for turning right
	Sprite mSpriteCenter;	// for going stright

	float mSpeed;

public:
	static String GetName() { return String("PlayerShip"); }

	PlayerShip() {}

	int Init();
	void SetPosition(Vector3 &pos);
	void Update(Single deltaTime);
	void SetSpeed(float s) { mSpeed = s; }
	float GetSpeed() { return mSpeed; }

};