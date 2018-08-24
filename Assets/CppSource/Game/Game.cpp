/// <summary>
/// Game-specific code for the native plugin
/// </summary>
/// <author>
/// Jackson Dunstan, 2017, http://JacksonDunstan.com
/// </author>
/// <license>
/// MIT
/// </license>

#include "Bindings.h"
#include "Game.h"

using namespace System;
using namespace UnityEngine;

namespace
{
	struct GameState
	{
		float BallDir;
	};
	
	GameState* gameState;
}

namespace MyGame
{
	void GameScript::Update()
	{
#if 0
		String name = GetName();
		String message("GameScript::Update:");
		Debug::Log(message);
		Debug::Log(name);
#endif
		if (GetGameObject().CompareTag(Game::GetName()))
		{
			// Game is updating
			return;
		}
		if ( GetGameObject().CompareTag(PlayerShip::GetName()))
		{
			// Player ship is updating
			PlayerShip::Update(GetGameObject(), GetTransform());
			return;
		}
	}
}

//////////////////////////////////////

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

		// The ball initially goes right
		gameState->BallDir = 1.0f;

		Game::GetInstance()->Init();
		delete Game::GetInstance();

		message = String("NativeGame Plugin End");
		Debug::Log(message);
	}
}
