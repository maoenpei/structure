

#include <windows.h>
#include "view/WinPlatform.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	view::WinPlatform plat;
	return plat.run(800, 480);
}

