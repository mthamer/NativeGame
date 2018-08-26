#pragma once

//
// base class for a game entity (ship, missile, etc)
//

#include "Bindings.h"

class GameEntity
{
protected:
	UnityEngine::GameObject mGo;

public:
	GameEntity() { }
	virtual ~GameEntity();

	int Init(System::String &name);
};
