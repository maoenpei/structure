#ifndef __BASE_I_RUNNABLE_H__
#define __BASE_I_RUNNABLE_H__

#include "IRef.h"

namespace core{

	class IRunnable : public virtual IRef
	{
	public:
		virtual void run() = 0;
	};

	class IRunnableInt : public virtual IRef
	{
	public:
		virtual void run(int value) = 0;
	};

	class IRunnableFloat : public virtual IRef
	{
	public:
		virtual void run(float value) = 0;
	};
	
};

#endif

