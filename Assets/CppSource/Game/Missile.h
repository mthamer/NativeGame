//
// projectile class
//

#pragma once

#include "Bindings.h"

using namespace System;
using namespace UnityEngine;

class Missile
{
	//	friend struct MyGame::GameScript;
private:
	GameObject mGo;
	String mSpritePath = { "missile" };
	Sprite mSprite;		// background sprite
	float mSpeed;
	bool mDead;			// set true to remove this

public:
	static String GetName() { return String("Missile"); }

	Missile() { }
	~Missile();
	int Init(const Vector3 &shipPos);
	void Update(Single deltaTime);
};

