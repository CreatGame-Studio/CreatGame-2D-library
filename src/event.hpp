#if !defined(__CG2_EVENT_HPP__)
#define __CG2_EVENT_HPP__

#include <map>

#include "types.hpp"

/*************************************************
* \author Ayrton Lachat
* \file cg2/event.hpp
* \date 28.03.22 at 12:08
*************************************************/

namespace cg2
{
	class Event
	{
		public:
			static void update();
			static bool isKeyPress(const char *key);
			static bool isRunning();
			static cg2::FPoint getMousePosition();
			static cg2::FPoint getMouseMotion();
			static bool isButtonPress(const char *button);

		private:
			static bool _running;
			static std::map<const char*, bool> _keyPress, _buttonPress;
			static cg2::FPoint _mousePosition, _mouseMotion;
	};
}

#endif