

#include <windows.h>
#include "WinPlatform.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	win32::WinPlatform plat;
	return plat.run(800, 480);
}

