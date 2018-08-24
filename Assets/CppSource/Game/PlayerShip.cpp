#include "PlayerShip.h"
#include "Game.h"

//
// load sprites
// set up game object
//
int PlayerShip::Init()
{
	mSpeed = 0.0002f;

	mSpriteLeft = Resources::Load<Sprite>(mSpriteLeftPath);
	mSpriteRight = Resources::Load<Sprite>(mSpriteRightPath);
	mSpriteCenter = Resources::Load<Sprite>(mSpriteCenterPath);

	mGo.SetName(GetName());
	mGo.SetTag(GetName());
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(mSpriteCenter);
	mGo.AddComponent<MyGame::BaseGameScript>();

	mGo.GetTransform().SetPosition(Vector3(0, -1.5, 0));	// start near the bottom

	return 0;	// ok
}

void PlayerShip::SetPosition(Vector3 &pos)
{
	mGo.GetTransform().SetPosition(pos);
	//mGo.GetComponent<SpriteRenderer>().GetTransform().SetPosition(pos);
}

void PlayerShip::Update(Single deltaTime)
{
	Vector3 pos = mGo.GetTransform().GetPosition();
	float speed = GetSpeed();
	bool dirty = false;

	if (Input::GetKey(String("a")))
	{
		// left
		pos.x = pos.x - speed * deltaTime;
		dirty = true;
	}
	if (Input::GetKey(String("d")))
	{
		// right
		pos.x = pos.x + speed * deltaTime;
		dirty = true;
	}
	if (Input::GetKey(String("w")))
	{
		// up
		pos.y = pos.y + speed * deltaTime;
		dirty = true;
	}
	if (Input::GetKey(String("s")))
	{
		// down
		pos.y = pos.y - speed * deltaTime;
		dirty = true;
	}

	if (dirty)
	{
		mGo.GetTransform().SetPosition(pos);
	}
}
