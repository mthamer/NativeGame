#pragma once

// 
// asteroid class
//

#include "Bindings.h"
#include "GameEntity.h"

class Rock : public GameEntity
{
private:
	const int NumSprites = 16;
	const float SpriteAnimTime = 0.1f;

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

