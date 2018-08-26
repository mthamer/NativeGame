//
// projectile class
//

#pragma once

#include "Bindings.h"
#include "GameEntity.h"

class Missile : public GameEntity
{
private:
	static Sprite MissileSprite;		// missile sprite
	float mSpeed;

public:
	static String GetName() { return String("Missile"); }

	Missile() { }
	virtual ~Missile() { }

	int Init(const Vector3 &shipPos);
	bool Update(float deltaTime);
};

