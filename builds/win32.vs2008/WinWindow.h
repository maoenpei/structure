#ifndef __WIN_WINDOW_H__
#define __WIN_WINDOW_H__

#include "view/IWindow.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <windows.h>

namespace win32{

	class WinWindow : public core::CRefObject, public virtual view::IWindow
	{
	public:
		virtual void getSize(int &width, int &height);
		virtual void setDispatcher(view::IWindowDispatcher *dispatcher);

		WinWindow(int w, int h);

		void createWindow();
		void destroyWindow();
		bool dispatchMessage(bool &quit);

		LRESULT handleMsg(UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		int Width, Height;
		core::TAuto<view::IWindowDispatcher> Dispatcher;
		HWND mHwnd;
		HGLRC mHRC;
		bool Captured;
	};

};

#endif

