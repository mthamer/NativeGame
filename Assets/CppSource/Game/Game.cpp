#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "Game.h"
#include "Rock.h"
#include "Explosion.h"
#include <Windows.h>	// for timeGetTime
#include <assert.h>

int Game::Init()
{
	int ret = GameEntity::Init(GetName());
	if (ret<0)
	{
		return ret;
	}

	mLastRockTime = 0;
	mLastUpdateTime = 0;
	mDeltaTime = 0;

	// attach main game script to Game object
	mGo.AddComponent<MyGame::BaseGameScript>();
	
	// add background image
	String bgSpritePath = { "background600x1024" };
	mBGSprite = Resources::Load<Sprite>(bgSpritePath);
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mBGSprite);
	mGo.GetTransform().SetPosition(Vector3(0, 0, 5));	// move back in Z

	ret = mPlayerShip.Init();
	if (ret != 0)
		return ret;

	return ret;
}

//
// Add an explosion into the scene at the given position
//
int Game::AddExplosion(Vector3 &pos)
{
	Explosion *explo = new Explosion();
	int ret = explo->Init(pos);
	mExplosions.push_back(explo);
	return ret;
}

bool Game::RemoveRock(Rock *rock)
{
	int i;
	for (i = 0; i < mRocks.size(); i++)
	{
		if (mRocks[i] == rock)
		{
			mRocks.erase(mRocks.begin() + i);
			delete rock;
			//Debug::Log(String("removing rock"));
			return true;
		}
	}

	assert(false);
	return false;
}

void Game::UpdateRocks(float deltaTime)
{
	int i;
	for (i = (int)mRocks.size() - 1; i >= 0; i--)
	{
		mRocks[i]->Update(deltaTime);
	}
}

bool Game::RemoveExplosion(Explosion *explo)
{
	int i;
	for (i = 0; i < mExplosions.size(); i++)
	{
		if (mExplosions[i] == explo)
		{
			mExplosions.erase(mExplosions.begin() + i);
			delete explo;
			//Debug::Log(String("removing explo"));
			return true;
		}
	}

	assert(false);
	return false;
}

void Game::UpdateExplosions(float deltaTime)
{
	int i;
	for (i = (int)mExplosions.size() - 1; i >= 0; i--)
	{
		mExplosions[i]->Update(deltaTime);
	}
}

void Game::Update(float deltaTime)
{
	const float timeBetweenRocks = 1.0f;

	int curTime = timeGetTime();
	mDeltaTime = ((curTime - mLastUpdateTime) / 1000.f);
	mLastUpdateTime = curTime;

	// update other game ents
	mPlayerShip.Update(deltaTime);	// collisions checked here

	if (curTime - mLastRockTime > timeBetweenRocks * 1000)
	{
		mLastRockTime = curTime;

		Rock *rock = new Rock();
		rock->Init();
		mRocks.push_back(rock);
		//Debug::Log(String("adding rock"));
	}

	UpdateRocks(deltaTime);
	UpdateExplosions(deltaTime);
}

// Called when the plugin is initialized
// This is mostly full of test code. Feel free to remove it all.
void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot)
{
	//gameState = (GameState*)memory;		// shared between C# and Native

	if (isFirstBoot) 
	{
		String message("NativeGame Plugin Begin");
		Debug::Log(message);

		Game::GetInstance()->Init();

		message = String("NativeGame Plugin End");
		Debug::Log(message);
	}
}
