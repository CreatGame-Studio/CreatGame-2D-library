#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "error.hpp"
#include "init.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/init.cpp
* \date 24.03.22 at 20:40
*************************************************/

void cg2::init(cg2::SubSystem subSystem)
{
	Uint32 sdlFlags = 0;

	if ((subSystem & cg2::SubSystem::VIDEO) != 0)
	{
		sdlFlags |= SDL_INIT_VIDEO;
	}

	if ((subSystem & cg2::SubSystem::AUDIO) != 0)
	{
		sdlFlags |= SDL_INIT_AUDIO;
	}


	if (SDL_Init(sdlFlags) != 0)
		throw cg2::Error(cg2::INIT, "Can't init SDL2");

	if (TTF_Init() != 0)
		throw cg2::Error(cg2::ErrorCode::INIT, "Can't init SDL_ttf");
}



void cg2::quit()
{
	TTF_Quit();
	SDL_Quit();
}