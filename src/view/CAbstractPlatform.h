#ifndef __BASE_PLATFORM_H__
#define __BASE_PLATFORM_H__

#include "IPlatform.h"
#include "core/CStaticObject.h"
#include "core/TAuto.h"

namespace view{

	class CAbstractPlatform : public core::CStaticObject, public virtual IPlatform
	{
	public:
		virtual IWindow *getWindow();
		
		virtual ILoopManager *getLoopManager();
		virtual void setTimeInterval(float dt);
		virtual void terminate();

		virtual engine::IGraphics *getGraphics();
		virtual engine::ISceneManager *getSceneManager();

		CAbstractPlatform();

	protected:
		core::TAuto<engine::ISceneManager> SceneManager;
		core::TAuto<engine::IGraphics> Graphics;
		core::TAuto<IWindow> Window;
		core::TAuto<ILoopManager> Looper;
		int MilliInterval;
		bool isTerminate;
	};
	
};

#endif

