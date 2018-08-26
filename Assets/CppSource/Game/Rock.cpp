
#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "Rock.h"
#include "Game.h"
#include <Windows.h>	// for timeGetTime()

// statics
const int Rock::NumSprites;
Sprite *Rock::RockSprites = nullptr;

int Rock::Init()
{
	int ret = GameEntity::Init(GetName());
	if (ret<0)
	{
		return ret;
	}

	mSpeed = Game::GetInstance()->GetPlayerShip().GetSpeed();

	// load Rock sprites
	if (RockSprites == nullptr)
	{
		RockSprites = new Sprite[NumSprites];
		int i;
		for (i = 0; i < NumSprites; i++)
		{
			char path[32];
			sprintf_s(path, "tile%03d", i);
			String spritePath(path);
			RockSprites[i] = Resources::Load<Sprite>(spritePath);
		}
	}

	mGo.AddComponent<SpriteRenderer>();
	mCurSprite = rand() % NumSprites;
	mGo.GetComponent<SpriteRenderer>().SetSprite(RockSprites[mCurSprite]);

	float xRand = ((float)rand() / RAND_MAX) * 2.5f - 1.25f;		// rand number from -1.25 to 1.25
	const float yStart = 1.5f;
	mGo.GetTransform().SetPosition(Vector3(xRand, yStart, 0));	

	return ret;
}

void Rock::Update(float deltaTime)
{
	//	Debug::Log(String("Rock Update"));

	// update sprite image
	const float spriteAnimTime = 0.1f;
	int curTime = timeGetTime();
	if (curTime - mLastSpriteTime > spriteAnimTime * 1000)
	{
		mLastSpriteTime = curTime;
		mCurSprite++;
		if (mCurSprite == NumSprites)
			mCurSprite = 0;
		mGo.GetComponent<SpriteRenderer>().SetSprite(RockSprites[mCurSprite]);
	}

	Vector3 &pos = mGo.GetTransform().GetPosition();
	pos.y = pos.y - mSpeed * deltaTime;
	mGo.GetTransform().SetPosition(pos);

	const float minY = -2.2f;
	if (pos.y < minY)
	{	// off screen
		//		Debug::Log(String("Rock Dead"));
		Game::GetInstance()->RemoveRock(this);
	}
}
