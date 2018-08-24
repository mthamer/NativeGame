#include "PlayerShip.h"

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

void PlayerShip::Update(GameObject &gameOb, Transform &transform)
{
	Vector3 pos = transform.GetPosition();
	pos.x = pos.x - .001f;
	transform.SetPosition(pos);
}
