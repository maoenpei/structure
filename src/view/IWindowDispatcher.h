#ifndef __BASE_I_WINDOW_DISPATCHER_H__
#define __BASE_I_WINDOW_DISPATCHER_H__

#include "core/IRef.h"

namespace view{
	
	enum{
		KeyCode_Back,
		KeyCode_Menu,
		KeyCode_Max
	};
	
	enum{
		PenTouch_Down,
		PenTouch_Move,
		PenTouch_Up
	};

	enum{
		InsertChar_Input,
		InsertChar_Remove,
		InsertChar_Return,
		InsertChar_Mark,
	};
	
	class IWindowDispatcher : public virtual core::IRef
	{
	public:
		virtual void onKeypress(unsigned int keyCode) = 0;
		virtual void onPentouch(int touchIndex, int x, int y, unsigned int keyTouch) = 0;
		virtual void onInsertChar(const char *text, unsigned int insertType) = 0;
	};
	
};

#endif

