#pragma once

// 
// asteroid class
//

#include "Bindings.h"
#include "GameEntity.h"

class Rock : public GameEntity
{
private:
	static const int NumSprites = 16;
	static Sprite *RockSprites;

	float mSpeed;
	int mCurSprite;
	int mLastSpriteTime;

public:
	static String GetName() { return String("Rock"); }

	Rock() { }
	virtual ~Rock() {}

	int Init();
	void Update(float deltaTime);
};

