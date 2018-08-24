#include "Missile.h"
#include "Game.h"

int Missile::Init(const Vector3 &shipPos)
{
	Debug::Log(String("Missile Init"));
	mSpeed = 0.0004f;
	mDead = false;

	// attach main game script to Game object
	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<MyGame::BaseGameScript>();

	// add background image
	mSprite = Resources::Load<Sprite>(mSpritePath);
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mSprite);

	const float shipYOffset = .27f;
	const float shipXOffset = -.005f;
	mGo.GetTransform().SetPosition(Vector3(shipPos.x + shipXOffset, shipPos.y + shipYOffset, shipPos.z));	// move back in Z

	return 0;
}

void Missile::Update(Single deltaTime)
{
	Debug::Log(String("Missile Update"));

	Vector3 pos = mGo.GetTransform().GetPosition();
	pos.y = pos.y + mSpeed * deltaTime;
	mGo.GetTransform().SetPosition(pos);

	const float maxY = 2.5f;
	if (pos.y > maxY)
	{	// off screen
		mDead = true;
		Debug::Log(String("Missile Dead"));
		Game::GetInstance()->GetPlayerShip().RemoveMissile(this);
	}
}
