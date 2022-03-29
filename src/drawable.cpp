#include <cmath>

#include <SDL2/SDL.h>

#include "drawable.hpp"
#include "error.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/drawable.cpp
* \date 25.03.22 at 17:40
*************************************************/

cg2::Rect::Rect() : x {0}, y {0}, w {0}, h {0}, flag {cg2::DrawingFlags::BORDER}
{

}



cg2::Rect::Rect(int _x, int _y, int _w, int _h) : x {_x}, y {_y}, w {_w}, h {_h}, flag {cg2::DrawingFlags::BORDER}
{

}



void cg2::Rect::draw(void *renderer) const
{
	SDL_Rect rect {x, y, w, h};

	if (flag == cg2::DrawingFlags::BORDER)
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



cg2::FRect::FRect() : x {0.0f}, y {0.0f}, w {0.0f}, h {0.0f}, flag {cg2::DrawingFlags::BORDER}
{

}



cg2::FRect::FRect(float _x, float _y, float _w, float _h) : x {_x}, y {_y}, w {_w}, h {_h}, flag {cg2::DrawingFlags::BORDER}
{

}



void cg2::FRect::draw(void *renderer) const
{
	SDL_FRect rect {x, y, w, h};

	if (flag == cg2::DrawingFlags::BORDER)
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



cg2::Circle::Circle() : x {0}, y {0}, r {0}, flag {cg2::DrawingFlags::BORDER}
{

}



cg2::Circle::Circle(int _x, int _y, int _r) : x {_x}, y {_y}, r {_r}, flag {cg2::DrawingFlags::BORDER}
{

}



void cg2::Circle::draw(void *renderer) const
{
	if (flag == cg2::DrawingFlags::BORDER)
	{
		const int diameter = r * 2;

		int _x = r - 1;
		int _y = 0;
		int tx = 1;
		int ty = 1;
		int error = tx - diameter;

		while (_x >= _y)
		{
			//  Each of the following renders an octant of the circle
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x + _x, y - _y);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x + _x, y + _y);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x - _x, y - _y);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x - _x, y + _y);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x + _y, y - _x);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x + _y, y + _x);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x - _y, y - _x);
			SDL_RenderDrawPoint((SDL_Renderer*)renderer, x - _y, y + _x);

			if (error <= 0)
			{
				++_y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--_x;
				tx += 2;
				error += (tx - diameter);
			}
		}
	}

	else
	{
		for (int w = 0; w < r * 2; w++)
		{
			for (int h = 0; h < r * 2; h++)
			{
				int dx = r - w; // horizontal offset
				int dy = r - h; // vertical offset
				if ((dx*dx + dy*dy) <= (r * r))
				{
					SDL_RenderDrawPoint((SDL_Renderer*)renderer, x + dx, y + dy);
				}
			}
		}
	}
}



cg2::FCircle::FCircle() : x {0.0f}, y {0.0f}, r {0.0f}, flag {cg2::DrawingFlags::BORDER}
{

}



cg2::FCircle::FCircle(float _x, float _y, float _r) : x {_x}, y {_y}, r {_r}, flag {cg2::DrawingFlags::BORDER}
{

}



void cg2::FCircle::draw(void *renderer) const
{
	if (flag == cg2::DrawingFlags::BORDER)
	{
		const float diameter = r * 2;

		float _x = r - 1;
		float _y = 0;
		float tx = 1;
		float ty = 1;
		float error = tx - diameter;

		while (_x >= _y)
		{
			//  Each of the following renders an octant of the circle
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x + _x, y - _y);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x + _x, y + _y);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x - _x, y - _y);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x - _x, y + _y);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x + _y, y - _x);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x + _y, y + _x);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x - _y, y - _x);
			SDL_RenderDrawPointF((SDL_Renderer*)renderer, x - _y, y + _x);

			if (error <= 0)
			{
				++_y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--_x;
				tx += 2;
				error += (tx - diameter);
			}
		}
	}

	else
	{
		for (float w = 0; w < r * 2; w++)
		{
			for (float h = 0; h < r * 2; h++)
			{
				float dx = r - w; // horizontal offset
				float dy = r - h; // vertical offset
				if ((dx*dx + dy*dy) <= (r * r))
				{
					SDL_RenderDrawPointF((SDL_Renderer*)renderer, x + dx, y + dy);
				}
			}
		}
	}
}