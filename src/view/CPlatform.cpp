

#include "CPlatform.h"

namespace view{

CPlatform::CPlatform()
	: MilliInterval(17)
	, isTerminate(false)
{}

IWindow *CPlatform::getWindow()
{
	return Window;
}

ILoopManager *CPlatform::getLoopManager()
{
	return Looper;
}

void CPlatform::setTimeInterval(float dt)
{
	MilliInterval = (int)(dt * 1000);
}

void CPlatform::terminate()
{
	isTerminate = true;
}

};


