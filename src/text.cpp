#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "error.hpp"
#include "text.hpp"
#include "window.hpp"


/*************************************************
* \author Ayrton Lachat
* \file cg2/text.cpp
* \date 28.03.22 at 16:42
*************************************************/

cg2::Font::Font() : _font {NULL}
{

}



cg2::Font::Font(const char *src, int size) : _font {NULL}
{
	this->load(src, size);
}



cg2::Font::~Font()
{
	this->unload();
}



void *cg2::Font::getFont() const noexcept
{
	return _font;
}



void cg2::Font::load(const char *src, int size)
{
	if (_font != NULL)
		this->unload();

	_font = TTF_OpenFont(src, size);
	if (_font == NULL)
		throw cg2::Error(cg2::ErrorCode::TEXT_FONT, "Can't load font");
}



void cg2::Font::unload()
{
	TTF_CloseFont((TTF_Font*)_font);
}






cg2::Text::Text() : _rect {}, _factor {1.0f}, _text {NULL}, _font {NULL}, _texture {NULL}, _color {}
{

}



cg2::Text::Text(void *font, const char *text, cg2::Color color)
{
	this->load(font, text, color);
}



cg2::Text::~Text()
{
	free(_text);
	this->unload();
}



void cg2::Text::changeText(const char *text)
{
	this->unload();
	this->load(_font, text, _color);
}



void cg2::Text::changeFont(void *font)
{
	this->unload();
	this->load(font, _text, _color);
}



void cg2::Text::changeColor(cg2::Color color)
{
	this->unload();
	this->load(_font, _text, color);
}



void cg2::Text::setPosition(float x, float y)
{
	_rect.x = x;
	_rect.y = y;
}



void cg2::Text::setFactor(float factor)
{
	_factor = factor;
	_rect.w *= _factor;
	_rect.h *= _factor;
}



cg2::FRect cg2::Text::getRect() const noexcept
{
	return _rect;
}



float cg2::Text::getFactor() const noexcept
{
	return _factor;
}



const char *cg2::Text::getText() const noexcept
{
	return _text;
}



void *cg2::Text::getFont() const noexcept
{
	return _font;
}



cg2::Color cg2::Text::getColor() const noexcept
{
	return _color;
}



void cg2::Text::draw(void *renderer) const
{
	SDL_FRect rect {_rect.x, _rect.y, _rect.w, _rect.h};

	if (SDL_RenderCopyF((SDL_Renderer*)renderer, (SDL_Texture*)_texture, NULL, &rect) != 0)
		throw cg2::Error(cg2::ErrorCode::DRAWING, "Can't render text");
}



void cg2::Text::load(void *font, const char *text, cg2::Color color)
{
	printf("1\n");

	_font = font;
	_color = color;

	if (_text != NULL)
	{
		free(_text);
		_text = NULL;
	}

	printf("2\n");

	_text = (char*)malloc(strlen(text) + 1);
	if (_text == NULL)
		throw cg2::Error(cg2::ErrorCode::TEXT_FONT, "Can't alloc memory for text");

	printf("3\n");

	strcpy(_text, text);

	printf("4\n");

	if (_texture != NULL)
		this->unload();

	printf("5\n");

	SDL_Surface *surface = TTF_RenderUTF8_Solid((TTF_Font*)_font, _text, {_color.r, _color.g, _color.b, _color.a});
	if (surface == NULL)
		throw cg2::Error(cg2::ErrorCode::TEXT_FONT, "Can't create text");

	printf("6\n");

	_texture = SDL_CreateTextureFromSurface((SDL_Renderer*)cg2::Window::getRenderer(), surface);

	_rect.w = (float)surface->w;
	_rect.h = (float)surface->h;

	SDL_FreeSurface(surface);

	printf("7\n");

	if (_texture == NULL)
		throw cg2::Error(cg2::ErrorCode::TEXT_FONT, "Can't convert surface to texture");
}



void cg2::Text::unload()
{
	printf("4.1\n");
	SDL_DestroyTexture((SDL_Texture*)_texture);
	printf("4.2\n");
}


