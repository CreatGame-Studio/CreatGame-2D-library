#include <SDL2/SDL.h>

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


	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw cg2::Error(cg2::INIT, "Can't init SDL2");
}



void cg2::quit()
{
	SDL_Quit();
}