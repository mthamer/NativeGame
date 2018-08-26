
#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "Missile.h"
#include "Game.h"
#include "Rect.h"

// statics
Sprite Missile::MissileSprite = nullptr;

int Missile::Init(const Vector3 &shipPos)
{
	int ret = GameEntity::Init(GetName());
	if (ret<0)
	{
		return ret;
	}

	mSpeed = Game::GetInstance()->GetPlayerShip().GetSpeed() * 2.0f;

	// add missile image
	if (MissileSprite == nullptr)
	{
		String spritePath = { "missile" };
		MissileSprite = Resources::Load<Sprite>(spritePath);
	}

	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(MissileSprite);

	const float shipYOffset = .27f;
	const float shipXOffset = -.005f;
	mGo.GetTransform().SetPosition(Vector3(shipPos.x + shipXOffset, shipPos.y + shipYOffset, shipPos.z));

	return ret;
}

// returns true if missile was removed
bool Missile::Update(float deltaTime)
{
//	Debug::Log(String("Missile Update"));

	Vector3 &pos = mGo.GetTransform().GetPosition();
	pos.y = pos.y + mSpeed * deltaTime;
	mGo.GetTransform().SetPosition(pos);

	const float maxY = 2.5f;
	if (pos.y > maxY)
	{	// off screen
//		Debug::Log(String("Missile Dead"));
		Game::GetInstance()->GetPlayerShip().RemoveMissile(this);
		return true;
	}
	return false;
}
