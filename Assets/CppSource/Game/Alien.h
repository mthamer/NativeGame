#pragma once

// 
// alien class
//

#include "Bindings.h"
#include "GameEntity.h"

class Alien : public GameEntity
{
private:
	static bool LoadedResources;
	static Sprite *AlienSprite;
	static AudioClip *Sound;

	float mSpeed;

public:
	static String GetName() { return String("Alien"); }

	Alien() { }
	virtual ~Alien();

	int Init();
	void Update(float deltaTime);
};

