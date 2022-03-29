#if !defined(__CG2_DRAWABLE_HPP__)
#define __CG2_DRAWABLE_HPP__

#include <cstdint>

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


	enum DrawingFlags
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
			DrawingFlags flag;
	};


	class FRect : public Drawable
	{
		public:
			FRect();
			FRect(float _x, float _y, float _w, float _h);

			virtual void draw(void *renderer) const;

			float x, y, w, h;
			DrawingFlags flag;
	};


	class Circle : public Drawable
	{
		public:
			Circle();
			Circle(int _x, int _y, int _r);

			virtual void draw(void *renderer) const;
			int x, y, r;
			DrawingFlags flag;
	};


	class FCircle : public Drawable
	{
		public:
			FCircle();
			FCircle(float _x, float _y, float _r);

			virtual void draw(void *renderer) const;
			float x, y, r;
			DrawingFlags flag;
	};
}

#endif