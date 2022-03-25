#if !defined(__CG2_WINDOW_HPP__)
#define __CG2_WINDOW_HPP__

#include "drawable.hpp"

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

			static void enableResizing(bool enable);
			static void setMaxSize(int w, int h);
			static void setMinSize(int w, int h);
			static void setViewportSize(int w, int h);
			static void setFullScreen(bool enable);

			static cg2::FRect getViewportRect();
			static bool isFullScreen();

			static int capFramerate(int framerate);
			static void update();

			static void setCurrentDrawColor(const Color &color);
			static void clear(const Color &color = {0, 0, 0, 255});
			static void draw(const Drawable &drawable);

			static void *getWindow();
			static void *getRenderer();

		private:
			static void *_window, *_renderer;
			static unsigned long long _startTick, _endTick;
			static cg2::FRect _viewportRect;
			static bool _isFullScreen;
	};
}

#endif