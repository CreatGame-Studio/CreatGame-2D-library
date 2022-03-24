#include <SDL2/SDL.h>

#include "error.hpp"
#include "window.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/window.cpp
* \date 24.03.22 at 20:54
*************************************************/


#define window (SDL_Window*)cg2::Window::_window
#define renderer (SDL_Renderer*)cg2::Window::_renderer


void *cg2::Window::_window {NULL}, *cg2::Window::_renderer {NULL};



void cg2::Window::create(const char *title, int x, int y, int w, int h)
{
	_window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
	if (window == NULL)
		throw cg2::Error(cg2::WINDOW_CREATE, "Can't create an SDL2 window");

	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		throw cg2::Error(cg2::WINDOW_CREATE, "Can't create an SDL2 renderer");
}



void cg2::Window::destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}



void cg2::Window::update()
{
	SDL_RenderPresent(renderer);
}



void *cg2::Window::getWindow()
{
	return _window;
}



void *cg2::Window::getRenderer()
{
	return _renderer;
}


