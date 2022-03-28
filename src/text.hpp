#if !defined(__CG2_TEXT_HPP__)
#define __CG2_TEXT_HPP__

#include "drawable.hpp"
#include "types.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/text.hpp
* \date 28.03.22 at 16:38
*************************************************/

namespace cg2
{
	class Font
	{
		public:
			Font();
			Font(const char *src, int size);
			~Font();

			void *getFont() const noexcept;

			void load(const char *src, int size);
			void unload();

		private:
			void *_font;
	};


	class Text : public cg2::Drawable
	{
		public:
			Text();
			Text(void *font, const char *text, cg2::Color color);
			~Text();

			void changeText(const char *text);
			void changeFont(void *font);
			void changeColor(cg2::Color color);
			void setPosition(float x, float y);
			void setFactor(float factor);

			cg2::FRect getRect() const noexcept;
			float getFactor() const noexcept;
			const char *getText() const noexcept;
			void *getFont() const noexcept;
			cg2::Color getColor() const noexcept;

			virtual void draw(void *renderer) const;

			void load(void *font, const char *text, cg2::Color color);
			void unload();

		private:
			cg2::FRect _rect;
			float _factor;
			char *_text;
			void *_font, *_texture;
			cg2::Color _color;
	};
}

#endif