#ifndef __BASE_SCENE_MANAGER_H__
#define __BASE_SCENE_MANAGER_H__

#include "ISceneManager.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include "view/IPlatform.h"
#include "graphics/IGraphics.h"

namespace engine{

	class CSceneManager : public core::CRefObject, public virtual ISceneManager
	{
	public:
		virtual void changeRootNode(ISceneNode *node);

		virtual void doDraw();

		CSceneManager(view::IPlatform *platform);

	private:
		core::TAuto<graphics::IGraphics> G;
		core::TAuto<ISceneNode> RootNode;
	};
	
};

#endif

