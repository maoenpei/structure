#ifndef __BASE_I_RUNNABLE_H__
#define __BASE_I_RUNNABLE_H__

#include "IRef.h"

namespace core{

	class IRunnable : public virtual IRef
	{
	public:
		virtual void run() = 0;
	};
	
};

#endif

