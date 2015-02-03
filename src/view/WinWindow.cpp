

#include "WinWindow.h"

#pragma comment(lib, "Opengl32.lib")

#define CLS_NAME L"MAIN_WINDOW"
#define WIN_CAPTION L"MainWindow"

#define WINOBJ_FROM_WINDOW(hwnd)		((view::WinWindow *)(GetWindowLong(hwnd, GWL_USERDATA)))

static LRESULT CALLBACK _WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	    case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_PAINT:
			PAINTSTRUCT ps;
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
	    case WM_LBUTTONDOWN:
		case WM_MOUSEMOVE:
		case WM_LBUTTONUP:
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_CHAR:
			view::WinWindow *window;
			window = WINOBJ_FROM_WINDOW(hWnd);
			return window->handleMsg(msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

namespace view{

	WinWindow::WinWindow(int w, int h)
		: Width(w)
		, Height(h)
		, Captured(false)
	{}

	void WinWindow::getSize(int &width, int &height)
	{
		width = Width;
		height = Height;
	}

	void WinWindow::setDispatcher(IWindowDispatcher *dispatcher)
	{
		Dispatcher = dispatcher;
	}

	LRESULT WinWindow::handleMsg(UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
			case WM_LBUTTONDOWN:
				Captured = true;
				SetCapture(mHwnd);
				if (Dispatcher){
					Dispatcher->onPentouch(0, (int)LOWORD(lParam), (int)HIWORD(lParam), PenTouch_Down);
				}
				break;
			case WM_MOUSEMOVE:
				if (Captured){
					if (Dispatcher){
						Dispatcher->onPentouch(0, (int)LOWORD(lParam), (int)HIWORD(lParam), PenTouch_Move);
					}
				}
				break;
			case WM_LBUTTONUP:
				if (Captured){
					Captured = false;
					ReleaseCapture();
					if (Dispatcher){
						Dispatcher->onPentouch(0, (int)LOWORD(lParam), (int)HIWORD(lParam), PenTouch_Up);
					}
				}
				break;
			case WM_CHAR:
				if (Dispatcher){
					if (wParam == VK_RETURN){
						Dispatcher->onInsertChar(NULL, InsertChar_Return);
					}else if (wParam == VK_BACK){
						Dispatcher->onInsertChar(NULL, InsertChar_Remove);
					}else{
						char utf8_str[8];
						WideCharToMultiByte(CP_UTF8, 0, (WCHAR *)(&wParam), 1, utf8_str, sizeof(utf8_str), 0, 0);
						Dispatcher->onInsertChar(utf8_str, InsertChar_Input);
					}
				}
				break;
			case WM_KEYDOWN:
				break;
		}
		return 0;
	}

	void WinWindow::createWindow()
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);

		WNDCLASS wc;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = _WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = CLS_NAME;

		RegisterClass(&wc);

		int scrWidth = GetSystemMetrics(SM_CXSCREEN);
		int scrHeight = GetSystemMetrics(SM_CYSCREEN);

		mHwnd = CreateWindowEx(
			WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
			CLS_NAME,
			WIN_CAPTION,
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			(scrWidth-Width)/2, (scrHeight-Height)/2, Width, Height,
			NULL, NULL, hInstance, NULL);

		SetWindowLong(mHwnd, GWL_USERDATA, (LONG)this);

		this->onCreateWnd(mHwnd);
		
		ShowWindow(mHwnd, SW_SHOW);
	}

	void WinWindow::destroyWindow()
	{
		this->onDestroyWnd();

		DestroyWindow(mHwnd);
		HINSTANCE hInstance = GetModuleHandle(NULL);
		UnregisterClass(CLS_NAME, hInstance);
	}

	bool WinWindow::dispatchMessage(bool &quit)
	{
		MSG msg;
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT){
				quit = true;
				return true;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			return true;
		}
		return false;
	}

};

