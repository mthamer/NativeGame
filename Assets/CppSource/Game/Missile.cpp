#include "Missile.h"
#include "Game.h"

// statics
Sprite Missile::MissileSprite = nullptr;

Missile::~Missile() 
{ 
	UnityEngine::Object::Destroy(mGo); 
}

int Missile::Init(const Vector3 &shipPos)
{
	mSpeed = Game::GetInstance()->GetPlayerShip().GetSpeed() * 2.0f;
//	Debug::Log(String("Missile Init"));

	// attach main game script to Game object
	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	// mGo.AddComponent<MyGame::BaseGameScript>();		// doesn't need a perframe update call

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

	return 0;
}

void Missile::Update(Single deltaTime)
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
	}
}
