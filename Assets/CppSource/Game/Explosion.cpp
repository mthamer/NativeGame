
#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "Explosion.h"
#include "Game.h"
#include <Windows.h>	// for timeGetTime()

// statics
Sprite *Explosion::ExplosionSprites = nullptr;

int Explosion::Init(Vector3 &startPos)
{
	int ret = GameEntity::Init(GetName());
	if (ret < 0)
	{
		return ret;
	}

	// load Explosion sprites once
	if (ExplosionSprites == nullptr)
	{
		ExplosionSprites = new Sprite[NumSprites];
		int i;
		for (i = 0; i < NumSprites; i++)
		{
			char path[32];
			sprintf_s(path, "explo64_b\\explo64_b%02d", i);
			String spritePath(path);
			ExplosionSprites[i] = Resources::Load<Sprite>(spritePath);
		}
	}

	mGo.AddComponent<SpriteRenderer>();
	mCurSprite = 0;
	mGo.GetComponent<SpriteRenderer>().SetSprite(ExplosionSprites[mCurSprite]);
	mGo.GetTransform().SetPosition(startPos);

	return ret;
}

void Explosion::Update(float deltaTime)
{
	//	Debug::Log(String("Explosion Update"));

	// update sprite image
	int curTime = timeGetTime();
	if (curTime - mLastSpriteTime > SpriteAnimTime * 1000)
	{
		mLastSpriteTime = curTime;
		mCurSprite++;
		if (mCurSprite == NumSprites)
		{
			mCurSprite = 0;
			Game::GetInstance()->RemoveExplosion(this);
		}
		else
		{
			mGo.GetComponent<SpriteRenderer>().SetSprite(ExplosionSprites[mCurSprite]);
		}
	}
}
