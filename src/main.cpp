#include <cstdio>

#include <SDL2/SDL.h>

#include "error.hpp"
#include "init.hpp"
#include "window.hpp"


int main(int argc, char *argv[])
{
	try
	{
		cg2::init(cg2::SubSystem::AUDIO);
		cg2::Window::create("CreatGame 2D Library", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 16 * 70, 9 * 70);

		bool running = true;
		SDL_Event event = {};

		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					case SDL_QUIT:
						running = false;
						break;
					
					default:
						break;
				}
			}

			cg2::Window::update();
		}
	}

	catch (const cg2::Error &error)
	{
		fprintf(stderr, "ERROR [%d] in file '%s', function '%s', line %d : %s\n", error.code, error.file, error.function, error.line, error.msg);
	}

	
	cg2::Window::destroy();
	cg2::quit();

	return 0;
}