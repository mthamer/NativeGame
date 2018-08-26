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
		const float deltaTime = Game::GetInstance()->GetDeltaTime();
#if 0
		char tmp[128];
		sprintf_s(tmp, "delta=%f", deltaTime);
		Debug::Log(String(tmp));
		float deltaTime = Time::GetDeltaTime();

		if (deltaTime > .2f)
		{
			deltaTime = .2f;
		}
		if (deltaTime < 0)
		{
			deltaTime = 0.016667f;		// 60 fps
		}
#endif
		if (GetGameObject().CompareTag(Game::GetName()))
		{
			// Game is updating
			Game::GetInstance()->Update(deltaTime);
			return;
		}
		if (GetGameObject().CompareTag(PlayerShip::GetName()))
		{
			// Player ship is updating
			Game::GetInstance()->GetPlayerShip().Update(deltaTime);
			return;
		}
	}
}

