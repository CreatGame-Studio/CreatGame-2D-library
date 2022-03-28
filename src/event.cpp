#include <SDL2/SDL.h>

#include "event.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/event.cpp
* \date 28.03.22 at 12:27
*************************************************/

bool cg2::Event::_running {true};
std::map<const char*, bool> cg2::Event::_keyPress {}, cg2::Event::_buttonPress {};
cg2::FPoint cg2::Event::_mousePosition {}, cg2::Event::_mouseMotion {};
SDL_Event event {};



const char *convertSDL_ScancodeToText(SDL_Scancode key)
{
	char *text = "-\0";

	if (key <= SDL_SCANCODE_Z)
	{
		text[0] = (char)((int)key + ((int)'A' - (int)SDL_SCANCODE_A));
	}

	else if (key == SDL_SCANCODE_0)
	{
		text[0] = '0';
	}

	else
	{
		text[0] = (char)((int)key + ((int)'1' - (int)SDL_SCANCODE_1));
	}

	return text;
}



void cg2::Event::update()
{
	_mouseMotion = {0.0f, 0.0f};

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				_keyPress[convertSDL_ScancodeToText(event.key.keysym.scancode)] = true;
				break;

			case SDL_KEYUP:
				_keyPress[convertSDL_ScancodeToText(event.key.keysym.scancode)] = false;
				break;

			case SDL_MOUSEMOTION:
				_mousePosition.x = (float)event.motion.x;
				_mousePosition.y = (float)event.motion.y;

				_mouseMotion.x = (float)event.motion.xrel;
				_mouseMotion.y = (float)event.motion.yrel;
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
					_buttonPress["left"] = true;
				else if (event.button.button == SDL_BUTTON_RIGHT)
					_buttonPress["right"] = true;
				else if (event.button.button == SDL_BUTTON_MIDDLE)
					_buttonPress["middle"] = true;
				break;

			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
					_buttonPress["left"] = false;
				else if (event.button.button == SDL_BUTTON_RIGHT)
					_buttonPress["right"] = false;
				else if (event.button.button == SDL_BUTTON_MIDDLE)
					_buttonPress["middle"] = false;
				break;

			case SDL_QUIT:
				_running = false;
				break;

			default:
				break;
		}
	}
}



bool cg2::Event::isKeyPress(const char *key)
{
	return _keyPress[key];
}



bool cg2::Event::isRunning()
{
	return _running;
}



cg2::FPoint cg2::Event::getMousePosition()
{
	return _mousePosition;
}



cg2::FPoint cg2::Event::getMouseMotion()
{
	return _mouseMotion;
}



bool cg2::Event::isButtonPress(const char *button)
{
	return _keyPress[button];
}


