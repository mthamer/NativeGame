
#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "PlayerShip.h"
#include "Game.h"
#include "Missile.h"
#include "Rock.h"
#include <assert.h>
#include <windows.h>

// for timeGetTime() usage
#pragma comment(lib, "winmm.lib")

//
// load sprites
// set up game object
//
int PlayerShip::Init()
{
	int ret = GameEntity::Init(GetName());
	if (ret < 0)
	{
		return ret;
	}

	// Path of sprites within the Unity Assets/Resources folder
	String spriteLeftPath = { "spaceship_high_left" };
	String spriteRightPath = { "spaceship_high_right" };
	String spriteCenterPath = { "spaceship_high_center" };
	String fireSoundPath = { "Sounds\\fire" };

	mSpeed = 1.5f;	// meters per sec
	mTimeBetweenShots = 0.25f;	// 4 shots per sec
	mLastShotTime = 0;

	mSpriteLeft = Resources::Load<Sprite>(spriteLeftPath);
	mSpriteRight = Resources::Load<Sprite>(spriteRightPath);
	mSpriteCenter = Resources::Load<Sprite>(spriteCenterPath);
	mFireSound = Resources::Load<AudioClip>(fireSoundPath);

	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteCenter);
	mGo.AddComponent<AudioSource>();

	mGo.GetTransform().SetPosition(Vector3(0, -1.5, 0));	// start near the bottom
	return ret;	// ok
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
		mGo.GetComponent<AudioSource>().PlayOneShot(mFireSound);
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
	Game* game = Game::GetInstance();
	int i;
	for (i = (int)mMissiles.size() - 1; i >= 0; i--)
	{
		if (mMissiles[i]->Update(deltaTime) == true)
			continue;	// missile was removed here

		// check for collision with rocks
//		MyGame::Rectangle<float> missileBounds = mMissiles[i]->GetBounds();
		Bounds missileBounds = mMissiles[i]->GetBounds();
		int j;
		for (j = (int)game->GetRocks().size() - 1; j >= 0; j--)
		{
			Bounds rockBounds = game->GetRocks()[j]->GetBounds();
			if (rockBounds.Intersects(missileBounds))
			{
				game->RemoveRock(game->GetRocks()[j]);
				RemoveMissile(mMissiles[i]);
				break;
			}
		}
	}
}

void PlayerShip::Update(float deltaTime)
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

	if ((Input::GetKeyUp(String("left")) || Input::GetKeyUp(String("right"))) &&
		!(Input::GetKey(String("left")) || Input::GetKey(String("right"))))
	{
		mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteCenter);
	}

	if (Input::GetKeyDown(String("left")))
	{
		mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteLeft);
	}

	if (Input::GetKeyDown(String("right")))
	{
		mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteRight);
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
