

#include <windows.h>
#include "WinDevice.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	win32::WinDevice device;
	return device.run(800, 480);
}

