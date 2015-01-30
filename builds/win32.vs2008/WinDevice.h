#ifndef __WIN_DEVICE_H__
#define __WIN_DEVICE_H__

#include "view/CDevice.h"

#include "core/IRegistry.h"
#include "view/CDevice.h"

namespace win32{

	class WinDevice : public view::CDevice
	{
	public:
		WinDevice();

		int run(int w, int h);
	};

};

#endif

