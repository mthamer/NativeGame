#include "Bindings.h"
#include "Game.h"

using namespace System;
using namespace UnityEngine;

int Game::Init()
{
	int ret = 0;	// ok

	// attach main game script to Game object
	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<MyGame::BaseGameScript>();

	ret = mPlayerShip.Init();
	if (ret != 0)
		return ret;

	return ret;
}

void Game::Update(Single deltaTime, GameObject &gameOb, Transform &transform)
{

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
		delete Game::GetInstance();

		message = String("NativeGame Plugin End");
		Debug::Log(message);
	}
}
