#include <cstdio>

#include <SDL2/SDL.h>

#include "error.hpp"
#include "event.hpp"
#include "image.hpp"
#include "init.hpp"
#include "text.hpp"
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

		cg2::Image image {"res/logo1024.png"};
		image.setInnerRect({256, 256, 512, 512});
		image.setPos(100, 200);
		image.setScaleFactor(0.5f);

		cg2::Font font {"res/arial.ttf", 40};

		cg2::Text text {font.getFont(), "Hello World !", {255, 150, 0, 255}};

		cg2::Rect rect1 {10, 20, 30, 40};
		cg2::FRect rect2 {30.0f, 50.0f, 60.5f, 10.0f};
		rect2.flag = cg2::RectDrawingFlags::FILL;
		/*int dt = 0;*/

		while (cg2::Event::isRunning())
		{
			cg2::Event::update();

			image.move(2.0f / 16.0f, 2.0f / 16.0f);


			cg2::Window::clear();

			cg2::Window::setCurrentDrawColor({0, 255, 0, 255});
			cg2::Window::draw(rect1);

			cg2::Window::setCurrentDrawColor({255, 0, 255, 255});
			cg2::Window::draw(rect2);

			cg2::Window::setCurrentDrawColor({255, 0, 0, 255});
			cg2::Window::draw(cg2::Window::getViewportRect());

			cg2::Window::draw(image);
			cg2::Window::draw(text);

			cg2::Window::update();


			cg2::Window::capFramerate(60);
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