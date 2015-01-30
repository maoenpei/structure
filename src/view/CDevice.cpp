

#include "CDevice.h"

namespace view{

CDevice::CDevice()
	: MilliInterval(17)
	, isTerminate(false)
{}

IWindow *CDevice::getWindow()
{
	return Window;
}

ILoopManager *CDevice::getLoopManager()
{
	return Looper;
}

void CDevice::setTimeInterval(float dt)
{
	MilliInterval = (int)(dt * 1000);
}

void CDevice::terminate()
{
	isTerminate = true;
}

};


