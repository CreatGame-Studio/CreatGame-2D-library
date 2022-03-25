#if !defined(__CG2_ERROR_HPP__)
#define __CG2_ERROR_HPP__

/*************************************************
* \author Ayrton Lachat
* \file cg2/error.hpp
* \date 24.03.22 at 20:16
*************************************************/

namespace cg2
{
	enum ErrorCode
	{
		INIT,
		WINDOW_CREATE,
		DRAWING
	};

	/**
	 * @brief The error handling structure
	 */

	class Error
	{
		public:
			Error(ErrorCode _code, const char *_msg, const char *_file, const char *_function, int _line) : code {_code}, msg {_msg}, file {_file}, function {_function}, line {_line}
			{

			}

			const ErrorCode code;
			const char *msg, *file, *function;
			int line;
	};
}

#define Error(code, msg) Error(code, msg, __FILE__, __func__, __LINE__)


#endif