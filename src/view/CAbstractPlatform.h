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

		virtual graphics::IGraphics *getGraphics();
		virtual graphics::IGraphicsCacher *getCacher();
		virtual engine::ISceneManager *getSceneManager();

		CAbstractPlatform();

	protected:
		core::TAuto<engine::ISceneManager> SceneManager;
		core::TAuto<graphics::IGraphics> Graphics;
		core::TAuto<graphics::IGraphicsCacher> Cacher;
		core::TAuto<IWindow> Window;
		core::TAuto<ILoopManager> Looper;
		int MilliInterval;
		bool isTerminate;
	};
	
};

#endif

