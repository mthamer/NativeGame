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

	static float Speed;

public:
	static String GetName() { return String("PlayerShip"); }
	static void Update(Single deltaTime, GameObject &gameOb, Transform &transform);
	static void SetSpeed(float s) { Speed = s; }
	static float GetSpeed() { return Speed; }

	PlayerShip() {}

	int Init();
	void SetPosition(Vector3 &pos);

};