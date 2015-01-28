

#include "WinDevice.h"
#include "WinWindow.h"

namespace win32{

	WinDevice::WinDevice()
		: isTerminate(false)
	{}

	void WinDevice::terminate()
	{
		isTerminate = true;
	}

	int WinDevice::run(int w, int h)
	{
		core::IRegistry *reg = getRegistry();
		reg->regist(this, IDEVICE_NAME);

		core::TAuto<WinWindow> window = new WinWindow(w, h);
		Window = window;

		window->createWindow();
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
				::Sleep(1);
			}
		}
		window->destroyWindow();
		reg->releaseAll();
		return 0;
	}

};


