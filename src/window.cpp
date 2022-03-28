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
unsigned long long cg2::Window::_startTick {0}, cg2::Window::_endTick {0};
cg2::FRect cg2::Window::_viewportRect {0.0f, 0.0f, 0.0f, 0.0f};
bool cg2::Window::_isFullScreen {false};
int cg2::Window::_dt {0};



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



void cg2::Window::enableResizing(bool enable)
{
	SDL_SetWindowResizable(window, (SDL_bool)enable);
}



void cg2::Window::setMaxSize(int w, int h)
{
	SDL_SetWindowMaximumSize(window, w, h);
}



void cg2::Window::setMinSize(int w, int h)
{
	SDL_SetWindowMinimumSize(window, w, h);
}



void cg2::Window::setViewportSize(int w, int h)
{
	if (SDL_RenderSetLogicalSize(renderer, w, h) != 0)
		throw Error(cg2::ErrorCode::WINDOW_CREATE, "Can't change viewport size");
	_viewportRect = {0.0f, 0.0f, (float)w, (float)h};
}



void cg2::Window::setFullScreen(bool enable)
{
	if (enable)
	{
		if (SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP) != 0)
			throw Error(cg2::ErrorCode::WINDOW_CREATE, "Can't enable full screen");
	}

	else
	{
		if (SDL_SetWindowFullscreen(window, 0) != 0)
			throw Error(cg2::ErrorCode::WINDOW_CREATE, "Can't disable full screen");
	}

	_isFullScreen = enable;
}



bool cg2::Window::isFullScreen()
{
	return _isFullScreen;
}



cg2::FRect cg2::Window::getViewportRect()
{
	return _viewportRect;
}



void cg2::Window::capFramerate(int framerate)
{
	_endTick = SDL_GetTicks64();
	_dt = _endTick - _startTick;

	if (_dt < 1000 / framerate)
	{
		SDL_Delay(1000 / framerate - _dt);
		_startTick = SDL_GetTicks64();
		_dt = 1000 / framerate;
		return;
	}

	_startTick = SDL_GetTicks64();
}



void cg2::Window::update()
{
	SDL_RenderPresent(renderer);
}



void cg2::Window::setCurrentDrawColor(const cg2::Color &color)
{
	if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
		throw Error(cg2::ErrorCode::DRAWING, "Can't change draw color");
}



void cg2::Window::clear(const cg2::Color &color)
{
	cg2::Window::setCurrentDrawColor(color);
	if (SDL_RenderClear(renderer) != 0)
		throw Error(cg2::ErrorCode::DRAWING, "Can't clear renderer");
}



void cg2::Window::draw(const cg2::Drawable &drawable)
{
	drawable.draw(_renderer);
}



void *cg2::Window::getWindow()
{
	return _window;
}



void *cg2::Window::getRenderer()
{
	return _renderer;
}



float cg2::Window::getDT()
{
	return (float)_dt;
}