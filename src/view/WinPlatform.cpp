

#include "WinPlatform.h"
#ifdef WINGL
#include "WinGLWindow.h"
#endif
#include "CLoopManager.h"

static int GetMilliCounter()
{
	LARGE_INTEGER liTime, liFreq;
	QueryPerformanceFrequency( &liFreq );
	QueryPerformanceCounter( &liTime );
	return (int)(liTime.QuadPart * 1000.0 / liFreq.QuadPart);
}

namespace view{

	WinPlatform::WinPlatform()
	{}

	int WinPlatform::run(int w, int h)
	{
		core::IRegistry *reg = getRegistry();
		reg->regist(this, IPLATFORM_NAME);
		
#ifdef WINGL
		WinWindow * window = new WinGLWindow(w, h);
#endif
		Window = window;

		CLoopManager * looper = new CLoopManager();
		Looper = looper;
		
		window->createWindow();
		int milli, milli2;
		bool quit = false;
		bool hasMessage;
		while(1){
			if (isTerminate){
				break;
			}
			hasMessage = window->dispatchMessage(quit);
			if (hasMessage && quit){
				break;
			}else if (!hasMessage){
				milli = GetMilliCounter();
				looper->doLoop(milli);
				milli2 = GetMilliCounter();
				if (milli2 - milli < MilliInterval){
					::Sleep(MilliInterval - (milli2 - milli));
				}
			}
		}
		window->destroyWindow();
		reg->releaseAll();
		
		return 0;
	}

};


