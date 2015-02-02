#ifndef __WIN_GL_WINDOW_H__
#define __WIN_GL_WINDOW_H__

#include "WinWindow.h"

namespace view{

	class WinGLWindow : public WinWindow
	{
	public:
		virtual void onCreateWnd(HWND hWnd);
		virtual void onDestroyWnd(HWND hWnd);

		WinGLWindow(int w, int h);

	private:
		HGLRC mHRC;
	};
};

#endif

