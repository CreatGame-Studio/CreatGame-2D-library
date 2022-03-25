#if !defined(__CG2_DRAWABLE_HPP__)
#define __CG2_DRAWABLE_HPP__

/*************************************************
* \author Ayrton Lachat
* \file cg2/drawable.hpp
* \date 25.03.22 at 17:34
*************************************************/

namespace cg2
{
	struct Color
	{
		uint8_t r, g, b, a;
	};

	class Drawable
	{
		public:
			virtual ~Drawable() {};
			virtual void draw(void *renderer) const = 0;
	};


	enum RectDrawingFlags
	{
		FILL, BORDER
	};


	class Rect : public Drawable
	{
		public:
			Rect();
			Rect(int _x, int _y, int _w, int _h);

			virtual void draw(void *renderer) const;

			int x, y, w, h;
			RectDrawingFlags flag;
	};


	class FRect : public Drawable
	{
		public:
			FRect();
			FRect(float _x, float _y, float _w, float _h);

			virtual void draw(void *renderer) const;

			float x, y, w, h;
			RectDrawingFlags flag;
	};
}

#endif