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
