
#include"Bindings.h"
using namespace System;
using namespace UnityEngine;

#include "Alien.h"
#include "Game.h"

// statics
Sprite *Alien::AlienSprite = nullptr;
bool Alien::LoadedResources = false;
AudioClip *Alien::Sound = nullptr;

Alien::~Alien()
{
	mGo.GetComponent<AudioSource>().Stop();
}

int Alien::Init()
{
	int ret = GameEntity::Init(GetName());
	if (ret < 0)
	{
		return ret;
	}

	// load Alien sprites once
	if (LoadedResources == false)
	{
		AlienSprite = new Sprite;
		*AlienSprite = Resources::Load<Sprite>(String("ufo"));
		Sound = new AudioClip;
		*Sound = Resources::Load<AudioClip>(String("Sounds\\saucerBig"));
		LoadedResources = true;
	}

	mSpeed = Game::GetInstance()->GetPlayerShip().GetSpeed() * 0.7f;
	mGo.AddComponent<SpriteRenderer>();
	mGo.GetComponent<SpriteRenderer>().SetSprite(*AlienSprite);
	mGo.AddComponent<AudioSource>();

	// start at upper right
	Vector3 startPos(1.5f, 1.6f, 0.0f);					
	SetPosition(startPos);

	// play sound looped
	mGo.GetComponent<AudioSource>().SetClip(*Sound);		
	mGo.GetComponent<AudioSource>().SetLoop(true);
	mGo.GetComponent<AudioSource>().Play();

	return ret;
}

//
// Move object from right to left
//
void Alien::Update(float deltaTime)
{
	//	Debug::Log(String("Alien Update"));
	Vector3 &pos = GetPosition();
	pos.x = pos.x - mSpeed * deltaTime;
	SetPosition(pos);

	const float minX = -1.6f;
	if (pos.x < minX)
	{	// off screen
//		Debug::Log(String("Removing Alien"));
		Game::GetInstance()->RemoveAlien();
	}

}
