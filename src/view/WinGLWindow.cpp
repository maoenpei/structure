

#include "WinGLWindow.h"


static void SetupPixelFormat(HDC hDC)
{
    int pixelFormat;

    PIXELFORMATDESCRIPTOR pfd =
    {   
        sizeof(PIXELFORMATDESCRIPTOR),  // size
        1,                          // version
        PFD_SUPPORT_OPENGL |        // OpenGL window
        PFD_DRAW_TO_WINDOW |        // render to window
        PFD_DOUBLEBUFFER,           // support double-buffering
        PFD_TYPE_RGBA,              // color type
        32,                         // prefered color depth
        0, 0, 0, 0, 0, 0,           // color bits (ignored)
        0,                          // no alpha buffer
        0,                          // alpha bits (ignored)
        0,                          // no accumulation buffer
        0, 0, 0, 0,                 // accum bits (ignored)
        16,                         // depth buffer
        0,                          // no stencil buffer
        0,                          // no auxiliary buffers
        PFD_MAIN_PLANE,             // main layer
        0,                          // reserved
        0, 0, 0,                    // no layer, visible, damage masks
    };

    pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);
}

namespace view{

	WinGLWindow::WinGLWindow(int w, int h)
		: WinWindow(w, h)
	{}

	void WinGLWindow::onCreateWnd(HWND hWnd)
	{
		HDC hDC = GetDC(hWnd);
		SetupPixelFormat(hDC);
		mHRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, mHRC);
	}

	void WinGLWindow::onDestroyWnd(HWND hWnd)
	{
		HDC hDC = GetDC(hWnd);
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(mHRC);
	}
	
};

