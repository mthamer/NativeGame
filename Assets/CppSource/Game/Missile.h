//
// projectile class
//

#pragma once

#include "Bindings.h"

using namespace System;
using namespace UnityEngine;

class Missile
{
private:
	static Sprite MissileSprite;		// missile sprite
	GameObject mGo;
	float mSpeed;

public:
	static String GetName() { return String("Missile"); }

	Missile() { }
	~Missile();
	int Init(const Vector3 &shipPos);
	void Update(Single deltaTime);
};

