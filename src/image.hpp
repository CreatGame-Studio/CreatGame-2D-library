#if !defined(__CG2_IMAGE_HPP__)
#define __CG2_IMAGE_HPP__

#include "drawable.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/image.hpp
* \date 28.03.22 at 11:37
*************************************************/

namespace cg2
{
	class Image : public cg2::Drawable
	{
		public:
			Image();
			Image(const char *src);
			~Image();

			void setPos(float x, float y);
			void setInnerRect(cg2::FRect innerRect);
			void setScaleFactor(float scaleFactor);

			cg2::FRect getRect() const noexcept;
			cg2::FRect getInnerRect() const noexcept;
			float getScaleFactor() const noexcept;

			virtual void draw(void *renderer) const;
			void load(const char *src);
			void unload();
			void move(float dx, float dy);

		private:
			cg2::FRect _rect, _innerRect;
			void *_texture;
			float _scaleFactor;
	};
}

#endif