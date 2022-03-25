#include <SDL2/SDL.h>

#include "drawable.hpp"
#include "error.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/drawable.cpp
* \date 25.03.22 at 17:40
*************************************************/

cg2::Rect::Rect() : x {0}, y {0}, w {0}, h {0}, flag {cg2::RectDrawingFlags::BORDER}
{

}



cg2::Rect::Rect(int _x, int _y, int _w, int _h) : x {_x}, y {_y}, w {_w}, h {_h}, flag {cg2::RectDrawingFlags::BORDER}
{

}



void cg2::Rect::draw(void *renderer) const
{
	SDL_Rect rect {x, y, w, h};

	if (flag == cg2::RectDrawingFlags::BORDER)
	{
		if (SDL_RenderDrawRect((SDL_Renderer*)renderer, &rect) != 0)
			throw Error(cg2::ErrorCode::DRAWING, "Can't render rect border");
	}

	else
	{
		if (SDL_RenderFillRect((SDL_Renderer*)renderer, &rect) != 0)
			throw Error(cg2::ErrorCode::DRAWING, "Can't render filled rect");
	}
}



cg2::FRect::FRect() : x {0.0f}, y {0.0f}, w {0.0f}, h {0.0f}, flag {cg2::RectDrawingFlags::BORDER}
{

}



cg2::FRect::FRect(float _x, float _y, float _w, float _h) : x {_x}, y {_y}, w {_w}, h {_h}, flag {cg2::RectDrawingFlags::BORDER}
{

}



void cg2::FRect::draw(void *renderer) const
{
	SDL_FRect rect {x, y, w, h};

	if (flag == cg2::RectDrawingFlags::BORDER)
	{
		if (SDL_RenderDrawRectF((SDL_Renderer*)renderer, &rect) != 0)
			throw Error(cg2::ErrorCode::DRAWING, "Can't render frect border");
	}

	else
	{
		if (SDL_RenderFillRectF((SDL_Renderer*)renderer, &rect) != 0)
			throw Error(cg2::ErrorCode::DRAWING, "Can't render filled frect");
	}
}


