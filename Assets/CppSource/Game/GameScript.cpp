#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "GameScript.h"
#include "Game.h"

//
// Main update script
//
namespace MyGame
{
	void GameScript::Update()
	{
		const float deltaTime = Game::GetInstance()->GetDeltaTime();
		Game::GetInstance()->Update(deltaTime);
	}
}

