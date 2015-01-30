

#include "WinPlatform.h"
#include "WinWindow.h"
#include "view/CLoopManager.h"

static int GetMilliCounter()
{
	LARGE_INTEGER liTime, liFreq;
	QueryPerformanceFrequency( &liFreq );
	QueryPerformanceCounter( &liTime );
	return (int)(liTime.QuadPart * 1000.0 / liFreq.QuadPart);
}

namespace win32{

	WinPlatform::WinPlatform()
	{}

	int WinPlatform::run(int w, int h)
	{
		core::IRegistry *reg = getRegistry();
		reg->regist(this, IPLATFORM_NAME);
		
		WinWindow * window = new WinWindow(w, h);
		Window = window;

		view::CLoopManager * looper = new view::CLoopManager();
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


