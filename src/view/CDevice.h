#ifndef __BASE_DEVICE_H__
#define __BASE_DEVICE_H__

#include "IDevice.h"
#include "core/CStaticObject.h"
#include "core/TAuto.h"

namespace view{

	class CDevice : public core::CStaticObject, public virtual IDevice
	{
	public:
		virtual IWindow *getWindow();
		
		virtual ILoopManager *getLoopManager();
		
		virtual void setTimeInterval(float dt);

		virtual void terminate();

		CDevice();

	protected:
		core::TAuto<IWindow> Window;
		core::TAuto<ILoopManager> Looper;
		int MilliInterval;
		bool isTerminate;
	};
	
};

#endif

