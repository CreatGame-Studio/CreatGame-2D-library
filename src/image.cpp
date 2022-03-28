#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "error.hpp"
#include "image.hpp"
#include "window.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/image.cpp
* \date 28.03.22 at 11:41
*************************************************/



cg2::Image::Image() : _rect {}, _innerRect {}, _texture {NULL}, _scaleFactor {1.0f}
{

}



cg2::Image::Image(const char *src) : _rect {}, _innerRect {}, _texture {NULL}, _scaleFactor {1.0f}
{
	this->load(src);
}



cg2::Image::~Image()
{
	this->unload();
}



void cg2::Image::setPos(float x, float y)
{
	_rect.x = x;
	_rect.y = y;
}



void cg2::Image::setInnerRect(cg2::FRect innerRect)
{
	_innerRect = innerRect;
	_rect.w = _innerRect.w * _scaleFactor;
	_rect.h = _innerRect.h * _scaleFactor;
}



void cg2::Image::setScaleFactor(float scaleFactor)
{
	_scaleFactor = scaleFactor;
	_rect.w *= _scaleFactor;
	_rect.h *= _scaleFactor;
}



cg2::FRect cg2::Image::getRect() const noexcept
{
	return _rect;
}



cg2::FRect cg2::Image::getInnerRect() const noexcept
{
	return _innerRect;
}



float cg2::Image::getScaleFactor() const noexcept
{
	return _scaleFactor;
}



void cg2::Image::draw(void *renderer) const
{
	SDL_FRect rect {_rect.x, _rect.y, _rect.w, _rect.h};
	SDL_Rect innerRect {(int)_innerRect.x, (int)_innerRect.y, (int)_innerRect.w, (int)_innerRect.h};

	if (SDL_RenderCopyF((SDL_Renderer*)renderer, (SDL_Texture*)_texture, &innerRect, &rect) != 0)
		throw cg2::Error(cg2::ErrorCode::DRAWING, "Can't draw image");
}



void cg2::Image::load(const char *src)
{
	if (_texture != NULL)
		this->unload();

	SDL_Surface *surface = IMG_Load(src);
	if (surface == NULL)
		throw Error(cg2::ErrorCode::IMAGE_CREATION, "Can't load image from memory");

	_rect = {0.0f, 0.0f, (float)surface->w, (float)surface->h};
	_innerRect = _rect;

	_texture = SDL_CreateTextureFromSurface((SDL_Renderer*)cg2::Window::getRenderer(), surface);

	SDL_FreeSurface(surface);

	if (_texture == NULL)
		throw cg2::Error(cg2::ErrorCode::IMAGE_CREATION, "Can't convert SDL_Surface to SDL_Texture");

	_scaleFactor = 1.0f;
}



void cg2::Image::unload()
{
	SDL_DestroyTexture((SDL_Texture*)_texture);
	_texture = NULL;
}



void cg2::Image::move(float dx, float dy)
{
	_rect.x += dx * cg2::Window::getDT();
	_rect.y += dy * cg2::Window::getDT();
}


