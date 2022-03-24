#if !defined(__CG2_WINDOW_HPP__)
#define __CG2_WINDOW_HPP__

/*************************************************
* \author Ayrton Lachat
* \file cg2/window.hpp
* \date 24.03.22 at 20:52
*************************************************/

namespace cg2
{
	class Window
	{
		public:
			static void create(const char *title, int x, int y, int w, int h);
			static void destroy();

			static void update();

			static void *getWindow();
			static void *getRenderer();

		private:
			static void *_window, *_renderer;
	};
}

#endif