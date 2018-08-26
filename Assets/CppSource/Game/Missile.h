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
//	static const Sprite &GetSprite() { return MissileSprite;  }

	Missile() { }
	virtual ~Missile() { }

	int Init(const Vector3 &shipPos);
	bool Update(float deltaTime);

	// TODO- get these from the actual sprite at runtime
	virtual float GetWidth() { return 4; }
	virtual float GetHeight() { return 11; }
};

