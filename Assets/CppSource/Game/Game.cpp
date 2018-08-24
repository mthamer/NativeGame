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
	void BallScript::Update()
	{
		Transform transform = GetTransform();
		Vector3 pos = transform.GetPosition();
		const float speed = 0.0001f;
		const float min = -2.0f;
		const float max = 2.0f;
		float distance = Time::GetDeltaTime() * speed * gameState->BallDir;
		Vector3 offset(distance, 0, 0);
		Vector3 newPos = pos + offset;
		if (newPos.x > max)
		{
			gameState->BallDir *= -1.0f;
			newPos.x = max - (newPos.x - max);
			if (newPos.x < min)
			{
				newPos.x = min;
			}
		}
		else if (newPos.x < min)
		{
			gameState->BallDir *= -1.0f;
			newPos.x = min + (min - newPos.x);
			if (newPos.x > max)
			{
				newPos.x = max;
			}
		}
		transform.SetPosition(newPos);
	}
}

// Called when the plugin is initialized
// This is mostly full of test code. Feel free to remove it all.
void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot)
{
	gameState = (GameState*)memory;
	if (isFirstBoot)
	{
		String message("Native Plugin Begin");
		Debug::Log(message);
		
		// The ball initially goes right
		gameState->BallDir = 1.0f;
		
		// Create the ball game object out of a sphere primitive
		String name("PlayerShip gameObject");
		GameObject go(name);

		go.AddComponent<SpriteRenderer>();

		String spriteLeftPath("spaceship_high_left");
		String spriteRightPath("spaceship_high_right");
		String spriteCenterPath("spaceship_high_center");
		Sprite spriteLeft = Resources::Load<Sprite>(spriteLeftPath);		
		Sprite spriteRight = Resources::Load<Sprite>(spriteRightPath);		
		Sprite spriteCenter = Resources::Load<Sprite>(spriteCenterPath);	
		String rock1Path("tile000");
		Sprite rock1 = Resources::Load<Sprite>(rock1Path);
		go.GetComponent<SpriteRenderer>().SetSprite(rock1);

		// Attach the ball script to make it bounce back and forth
		go.AddComponent<MyGame::BaseBallScript>();
	}
}
