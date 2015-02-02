#ifndef __WIN_PLATFORM_H__
#define __WIN_PLATFORM_H__

#include "core/IRegistry.h"
#include "CPlatform.h"

namespace view{

	class WinPlatform : public CPlatform
	{
	public:
		WinPlatform();

		int run(int w, int h);
	};

};

#endif

