#pragma once

#include "Bindings.h"

//
// Interface to Main Unity game script
//
namespace MyGame
{
	struct GameScript : MyGame::BaseGameScript
	{
		MY_GAME_GAME_SCRIPT_DEFAULT_CONSTRUCTOR
			void Update() override;
	};
}
