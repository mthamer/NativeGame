//
// implementation for base game ent class
//

#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "GameEntity.h"

GameEntity::~GameEntity()
{
	UnityEngine::Object::Destroy(mGo);
}

int GameEntity::Init(System::String &name)
{
	mGo.SetName(name);

	return 0;
}

#if 0
//
// return bounding rect
//
MyGame::Rectangle<float> GameEntity::GetBounds()
{
	Vector3 &pos = mGo.GetTransform().GetPosition();
	MyGame::Point<float> topLeft(pos.x - GetWidth() / 2.0f, pos.y + GetHeight() / 2.0f);
	MyGame::Point<float> bottomRight(pos.x + GetWidth() / 2.0f, pos.y - GetHeight() / 2.0f);
	return MyGame::Rectangle<float>(topLeft, bottomRight);
}
#endif

// 
// return unity sprite bounds
//
Bounds GameEntity::GetBounds()
{
	return mGo.GetComponent<SpriteRenderer>().GetBounds();
}
