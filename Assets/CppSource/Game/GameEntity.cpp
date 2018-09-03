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

// bindings code has a bug when generating this, so I made my own
Vector3 operator*(Vector3 v, float d)
{
	return Vector3(v.x*d, v.y*d, v.z*d);
}

// 
// return unity sprite bounds
//
Bounds GameEntity::GetBounds()
{
	return mGo.GetComponent<SpriteRenderer>().GetBounds();
}

//
// static helper
//
void GameEntity::ScaleBounds(Bounds &bounds, float scaleFactor)
{
	Vector3 &max = bounds.GetMax();
	Vector3 &min = bounds.GetMin();
	Vector3 ctr = (min + max) * 0.5f;
	Vector3 ctrToMax = max - ctr;
	Vector3 ctrToMin = min - ctr;

	bounds.SetMax(ctr + ctrToMax * scaleFactor);
	bounds.SetMin(ctr + ctrToMin * scaleFactor);
}

Vector3 GameEntity::GetPosition()
{
	return mGo.GetTransform().GetPosition();
}


void GameEntity::SetPosition(Vector3 &pos)
{
	mGo.GetTransform().SetPosition(pos);
}

