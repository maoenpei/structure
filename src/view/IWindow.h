#ifndef __BASE_I_WINDOW_H__
#define __BASE_I_WINDOW_H__

#include "core/IRef.h"
#include "IWindowDispatcher.h"

namespace view{
	
	class IWindow : public virtual core::IRef
	{
	public:
		virtual void getSize(int &width, int &height) = 0;
		virtual void setDispatcher(IWindowDispatcher *dispatcher) = 0;
		
	};
	
};

#endif

