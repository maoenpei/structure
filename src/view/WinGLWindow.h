#ifndef __WIN_GL_WINDOW_H__
#define __WIN_GL_WINDOW_H__

#include "WinWindow.h"

namespace view{

	class WinGLWindow : public WinWindow
	{
	public:
		virtual void onCreateWnd(HWND hWnd);
		virtual void onDestroyWnd();
		virtual void onSwapBuffer();

		WinGLWindow(int w, int h);

	private:
		HWND mHwnd;
		HDC mHDC;
		HGLRC mHRC;
	};
};

#endif

