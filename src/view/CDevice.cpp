

#include "CDevice.h"

namespace view{

IWindow *CDevice::getWindow()
{
	return Window;
}

ILoopManager *CDevice::getLoopManager()
{
	return Looper;
}

};


