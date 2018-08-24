#include "Bindings.h"
#include "Game.h"
#include "GameScript.h"

using namespace System;
using namespace UnityEngine;

//
// Main update script
//
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

#if 0	// not sure shy this crashes
		String horiz("Horizontal");
		String vert("Vertical");
		float h = Input::GetAxis(horiz);
		float v = Input::GetAxis(vert);
#endif

		if (GetGameObject().CompareTag(Game::GetName()))
		{
			// Game is updating
			Game::GetInstance()->Update(Time::GetDeltaTime());
			return;
		}
		if (GetGameObject().CompareTag(PlayerShip::GetName()))
		{
			// Player ship is updating
			Game::GetInstance()->GetPlayerShip().Update(Time::GetDeltaTime());
			return;
		}
	}
}

