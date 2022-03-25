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

		cg2::Window::enableResizing(true);
		cg2::Window::setMinSize(16 * 70, 9 * 70);
		cg2::Window::setViewportSize(16 * 70, 9 * 70);

		bool running = true;
		SDL_Event event = {};
		cg2::Rect rect1 {10, 20, 30, 40};
		cg2::FRect rect2 {30.0f, 50.0f, 60.5f, 10.0f};
		rect2.flag = cg2::RectDrawingFlags::FILL;
		/*int dt = 0;*/

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

			cg2::Window::clear();

			cg2::Window::setCurrentDrawColor({0, 255, 0, 255});
			cg2::Window::draw(rect1);

			cg2::Window::setCurrentDrawColor({255, 0, 255, 255});
			cg2::Window::draw(rect2);

			cg2::Window::setCurrentDrawColor({255, 0, 0, 255});
			cg2::Window::draw(cg2::Window::getViewportRect());

			cg2::Window::update();


			/*dt = */cg2::Window::capFramerate(60);
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