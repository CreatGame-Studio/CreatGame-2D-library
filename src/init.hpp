#if !defined(__CG2_INIT_HPP__)
#define __CG2_INIT_HPP__

/*************************************************
* \author Ayrton Lachat
* \file cg2/init.hpp
* \date 24.03.22 at 20:35
*************************************************/

namespace cg2
{
	enum SubSystem
	{
		VIDEO = 0b00000001,
		AUDIO = 0b00000010,
		EVERYTHING = VIDEO | AUDIO
	};

	void init(SubSystem subSystem);
	void quit();
}

#endif