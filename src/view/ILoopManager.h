#ifndef __BASE_I_LOOP_MANAGER_H__
#define __BASE_I_LOOP_MANAGER_H__

#include "core/IRef.h"
#include "core/IRunnable.h"

namespace view{
	
	class ILoopManager : public virtual core::IRef
	{
	public:
		virtual unsigned int addLoopItem(core::IRunnable *runnable) = 0;
		virtual unsigned int addLoopItem(core::IRunnableInt *irunnable, float dt, bool repeat) = 0;
		virtual void removeLoopKey(unsigned int key) = 0;
	};
	
}

#endif

