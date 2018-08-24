#include "PlayerShip.h"
#include "Game.h"

float PlayerShip::Speed = 0.0001f;

//
// load sprites
// set up game object
//
int PlayerShip::Init()
{
	mSpriteLeft = Resources::Load<Sprite>(mSpriteLeftPath);
	mSpriteRight = Resources::Load<Sprite>(mSpriteRightPath);
	mSpriteCenter = Resources::Load<Sprite>(mSpriteCenterPath);

	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteCenter);
	mGo.AddComponent<MyGame::BaseGameScript>();

	return 0;	// ok
}

void PlayerShip::SetPosition(Vector3 &pos)
{
	mGo.GetTransform().SetPosition(pos);
	//mGo.GetComponent<SpriteRenderer>().GetTransform().SetPosition(pos);
}

void PlayerShip::Update(Single deltaTime, GameObject &gameOb, Transform &transform)
{
	Vector3 pos = transform.GetPosition();
	float speed = GetSpeed();

	if (Input::GetKey(String("a")))
	{
		// left
		pos.x = pos.x - speed * deltaTime;
	}
	if (Input::GetKey(String("d")))
	{
		// right
		pos.x = pos.x + speed * deltaTime;
	}
	if (Input::GetKey(String("w")))
	{
		// up
		pos.y = pos.y + speed * deltaTime;
	}
	if (Input::GetKey(String("s")))
	{
		// down
		pos.y = pos.y - speed * deltaTime;
	}

	transform.SetPosition(pos);
}
