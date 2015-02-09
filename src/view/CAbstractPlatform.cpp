

#include "CAbstractPlatform.h"

namespace view{

CAbstractPlatform::CAbstractPlatform()
	: MilliInterval(17)
	, isTerminate(false)
{}

IWindow *CAbstractPlatform::getWindow()
{
	return Window;
}

ILoopManager *CAbstractPlatform::getLoopManager()
{
	return Looper;
}

void CAbstractPlatform::setTimeInterval(float dt)
{
	MilliInterval = (int)(dt * 1000);
}

void CAbstractPlatform::terminate()
{
	isTerminate = true;
}

engine::IGraphics *CAbstractPlatform::getGraphics()
{
	return Graphics;
}

engine::ISceneManager *CAbstractPlatform::getSceneManager()
{
	return SceneManager;
}

};


