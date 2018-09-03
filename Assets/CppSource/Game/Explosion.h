#pragma once

// 
// explosion class
//

#include "Bindings.h"
#include "GameEntity.h"

class Explosion : public GameEntity
{
private:
	const int NumSprites = 62;
	const float SpriteAnimTime = 0.01f;

	static Sprite *ExplosionSprites;

	int mCurSprite;					// index
	int mLastSpriteTime;

public:
	static String GetName() { return String("Explosion"); }

	Explosion() { }
	virtual ~Explosion() {}

	int Init(Vector3 &startPos);
	void Update(float deltaTime);
};

