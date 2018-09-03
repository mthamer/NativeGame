#pragma once

//
// base class for a game entity (ship, missile, etc)
//

#include "Bindings.h"

class GameEntity
{
protected:
	GameObject mGo;

public:
	GameEntity() { }
	virtual ~GameEntity();

	int Init(System::String &name);
	Bounds GetBounds();

	Vector3 GetPosition();
	void SetPosition(Vector3 &pos);
};
