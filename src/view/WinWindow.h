#ifndef __WIN_WINDOW_H__
#define __WIN_WINDOW_H__

#include "IWindow.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <windows.h>

namespace view{

	class WinWindow : public core::CRefObject, public virtual IWindow
	{
	public:
		virtual void getSize(int &width, int &height);
		virtual void setDispatcher(IWindowDispatcher *dispatcher);

		WinWindow(int w, int h);

		void createWindow();
		void destroyWindow();
		bool dispatchMessage(bool &quit);

		virtual void onCreateWnd(HWND hWnd) = 0;
		virtual void onDestroyWnd() = 0;
		virtual void onSwapBuffer() = 0;

		LRESULT handleMsg(UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		int Width, Height;
		core::TAuto<IWindowDispatcher> Dispatcher;
		HWND mHwnd;
		bool Captured;
	};

};

#endif

