#ifndef __BASE_PLATFORM_H__
#define __BASE_PLATFORM_H__

#include "IPlatform.h"
#include "core/CStaticObject.h"
#include "core/TAuto.h"

namespace view{

	class CPlatform : public core::CStaticObject, public virtual IPlatform
	{
	public:
		virtual IWindow *getWindow();
		
		virtual ILoopManager *getLoopManager();
		
		virtual void setTimeInterval(float dt);

		virtual void terminate();

		CPlatform();

	protected:
		core::TAuto<IWindow> Window;
		core::TAuto<ILoopManager> Looper;
		int MilliInterval;
		bool isTerminate;
	};
	
};

#endif

