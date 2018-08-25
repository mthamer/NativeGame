#include "PlayerShip.h"
#include "Game.h"
#include "Missile.h"
#include <assert.h>
#include <windows.h>

//
// load sprites
// set up game object
//
int PlayerShip::Init()
{
	mSpeed = 0.0002f;
	mTimeBetweenShots = 0.2f;	// 5 shots per sec
	mLastShotTime = 0;

	mSpriteLeft = Resources::Load<Sprite>(mSpriteLeftPath);
	mSpriteRight = Resources::Load<Sprite>(mSpriteRightPath);
	mSpriteCenter = Resources::Load<Sprite>(mSpriteCenterPath);

	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteCenter);
	mGo.AddComponent<MyGame::BaseGameScript>();

	mGo.GetTransform().SetPosition(Vector3(0, -1.5, 0));	// start near the bottom

	return 0;	// ok
}

void PlayerShip::SetPosition(Vector3 &pos)
{
	mGo.GetTransform().SetPosition(pos);
}

void PlayerShip::FireMissile()
{
	int curTime = timeGetTime();
	if (curTime - mLastShotTime > mTimeBetweenShots * 1000)
	{
		mLastShotTime = curTime;
		Missile *missile = new Missile();
		missile->Init(mGo.GetTransform().GetPosition());
		mMissiles.push_back(missile);
	}
}

bool PlayerShip::RemoveMissile(Missile *missile)
{
	int i;
	for (i = 0; i < mMissiles.size(); i++)
	{
		if (mMissiles[i] == missile)
		{
			mMissiles.erase(mMissiles.begin() + i);
			delete missile;
			return true;
		}
	}

	assert(false);
	return false;
}


void PlayerShip::UpdateMissiles(Single deltaTime)
{
	int i;
	for (i = (int)mMissiles.size()-1; i>=0; i--)
	{
		mMissiles[i]->Update(deltaTime);
	}
}

void PlayerShip::Update(Single deltaTime)
{
	const float maxX = 1.1f;
	const float minX = -1.1f;
	const float maxY = 0.f;
	const float minY = -1.5f;

	UpdateMissiles(deltaTime);

	Vector3 pos = mGo.GetTransform().GetPosition();
	bool dirty = false;

	if (Input::GetKey(String("space")))
	{
		FireMissile();
	}

	if (Input::GetKey(String("left")) && pos.x >= minX)
	{
		// left
		pos.x = pos.x - mSpeed * deltaTime;
		dirty = true;
	}
	if (Input::GetKey(String("right")) && pos.x <= maxX)
	{
		// right
		pos.x = pos.x + mSpeed * deltaTime;
		dirty = true;
	}
	
	if (Input::GetKey(String("up")) && pos.y <= maxY)
	{
		// up
		pos.y = pos.y + mSpeed * deltaTime;
		dirty = true;
	}
	if (Input::GetKey(String("down")) && pos.y >= minY)
	{
		// down
		pos.y = pos.y - mSpeed * deltaTime;
		dirty = true;
	}

	if (dirty)
	{
		mGo.GetTransform().SetPosition(pos);
	}
}
