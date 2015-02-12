

#include "WinPlatform.h"
#ifdef WINGL
#include "WinGLWindow.h"
#endif
#include "CLoopManager.h"
#include "core/IAllocator.h"
#include "graphics/GLGraphics.h"

static int GetMilliCounter()
{
	LARGE_INTEGER liTime, liFreq;
	QueryPerformanceFrequency( &liFreq );
	QueryPerformanceCounter( &liTime );
	return (int)(liTime.QuadPart * 1000.0 / liFreq.QuadPart);
}

namespace view{

	class DllAllocator : public core::CStaticObject, public virtual core::IAllocator
	{
	public:
		virtual void *alloc(size_t siz){return ::operator new (siz);}
		virtual void free(void *ptr){::operator delete (ptr);}
	};

	WinPlatform::WinPlatform()
	{}

	int WinPlatform::run(int w, int h)
	{
		core::IRegistry *reg = getRegistry();
		reg->regist(this, IPLATFORM_NAME);

		DllAllocator allocator;
		reg->regist(&allocator, IALLOCATOR_NAME);
		
#ifdef WINGL
		WinWindow * window = new WinGLWindow(w, h);
		graphics::GLGraphics *graph = new graphics::GLGraphics();
#endif
		Graphics = graph;
		Window = window;

		CLoopManager * looper = new CLoopManager();
		Looper = looper;
		
		window->createWindow();
		graph->initAPIs();
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
				window->onSwapBuffer();
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


