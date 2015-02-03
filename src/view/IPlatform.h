#ifndef __BASE_I_PLATFORM_H__
#define __BASE_I_PLATFORM_H__

#include "core/IRef.h"
#include "IWindow.h"
#include "ILoopManager.h"

namespace view{
	
	class IPlatform : public virtual core::IRef
	{
	public:
		virtual IWindow *getWindow() = 0;
		
		virtual ILoopManager *getLoopManager() = 0;
		virtual void setTimeInterval(float dt) = 0;
		virtual void terminate() = 0;
		
		//virtual ISceneManager *getSceneManager() = 0;
	};

};

// find interface by name using IRegistry
#define IPLATFORM_NAME		"::IPlatformInstance"

#endif

