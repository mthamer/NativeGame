#include "Bindings.h"
#include "Game.h"
#include "Rock.h"
#include <Windows.h>	// for timeGetTime
#include <assert.h>

using namespace System;
using namespace UnityEngine;

int Game::Init()
{
	int ret = 0;	// ok

	mLastRockTime = 0;
	mLastUpdateTime = 0;
	mDeltaTime = 0;

	// attach main game script to Game object
	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<MyGame::BaseGameScript>();
	
	// add bacvkground image
	mBGSprite = Resources::Load<Sprite>(mBGSpritePath);
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mBGSprite);
	mGo.GetTransform().SetPosition(Vector3(0, 0, 5));	// move back in Z

	ret = mPlayerShip.Init();
	if (ret != 0)
		return ret;

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

void Game::UpdateRocks(Single deltaTime)
{
	int i;
	for (i = (int)mRocks.size() - 1; i >= 0; i--)
	{
		mRocks[i]->Update(deltaTime);
	}
}

void Game::Update(Single deltaTime)
{
	const float timeBetweenRocks = 1.0f;

	int curTime = timeGetTime();
	mDeltaTime = ((curTime - mLastUpdateTime) / 1000.f);
	mLastUpdateTime = curTime;

	if (curTime - mLastRockTime > timeBetweenRocks * 1000)
	{
		mLastRockTime = curTime;

		Rock *rock = new Rock();
		rock->Init();
		mRocks.push_back(rock);
		//Debug::Log(String("adding rock"));
	}

	UpdateRocks(deltaTime);
}

// Called when the plugin is initialized
// This is mostly full of test code. Feel free to remove it all.
void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot)
{
	gameState = (GameState*)memory;		// shared between C# and Native

	if (isFirstBoot) 
	{
		String message("NativeGame Plugin Begin");
		Debug::Log(message);

		Game::GetInstance()->Init();

		message = String("NativeGame Plugin End");
		Debug::Log(message);
	}
}
