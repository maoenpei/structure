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

	protected:
		core::TAuto<IWindow> Window;
		core::TAuto<ILoopManager> Looper;
	};
	
};

#endif

