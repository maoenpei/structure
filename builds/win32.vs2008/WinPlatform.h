#ifndef __WIN_PLATFORM_H__
#define __WIN_PLATFORM_H__

#include "core/IRegistry.h"
#include "view/CPlatform.h"

namespace win32{

	class WinPlatform : public view::CPlatform
	{
	public:
		WinPlatform();

		int run(int w, int h);
	};

};

#endif

