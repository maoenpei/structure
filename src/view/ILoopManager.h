#ifndef __BASE_I_LOOP_MANAGER_H__
#define __BASE_I_LOOP_MANAGER_H__

#include "core/IRef.h"
#include "core/IRunnable.h"

namespace view{
	
	class ILoopManager : public virtual core::IRef
	{
	public:
		virtual void addLoopItem(core::IRunnable *runnable) = 0;
		virtual void addLoopItem(core::IRunnable *runnable, float dt, bool repeat) = 0;
	};
	
}

#endif

