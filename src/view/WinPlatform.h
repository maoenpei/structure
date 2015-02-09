#ifndef __WIN_PLATFORM_H__
#define __WIN_PLATFORM_H__

#include "core/IRegistry.h"
#include "CAbstractPlatform.h"

namespace view{

	class WinPlatform : public CAbstractPlatform
	{
	public:
		WinPlatform();

		int run(int w, int h);
	};

};

#endif

