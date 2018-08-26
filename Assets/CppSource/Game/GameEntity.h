#pragma once

//
// base class for a game entity (ship, missile, etc)
//

#include "Bindings.h"
#include "Rect.h"

class GameEntity
{
protected:
	GameObject mGo;

public:
	GameEntity() { }
	virtual ~GameEntity();

	virtual float GetWidth() { return 0; }
	virtual float GetHeight() { return 0; }

	int Init(System::String &name);
//	MyGame::Rectangle<float> GetBounds();
	GameObject &GetGameObject() { return mGo; }
	Bounds GetBounds();
};
