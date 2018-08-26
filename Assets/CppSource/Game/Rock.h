#pragma once

// 
// asteroid class
//

#include "Bindings.h"

using namespace System;
using namespace UnityEngine;

class Rock
{
private:
	static const int NumSprites = 16;
	static Sprite *RockSprites;
	GameObject mGo;
	float mSpeed;
	int mCurSprite;
	int mLastSpriteTime;

public:
	static String GetName() { return String("Rock"); }

	Rock() { }
	~Rock();
	int Init();
	void Update(Single deltaTime);
};

