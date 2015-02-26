#ifndef __BASE_SCENE_NODE_H__
#define __BASE_SCENE_NODE_H__

#include "ISceneNode.h"
#include "core/CRefObject.h"
#include "ISceneManager.h"
#include "graphics/IGraphics.h"
#include "graphics/IGraphicsCacher.h"
#include "core/TAuto.h"
#include "view/IPlatform.h"

namespace engine{

	class CSceneNode : public core::CRefObject, public ISceneNode
	{
	public:
		virtual INodeCamera *getCamera();

		CSceneNode(view::IPlatform *platform);

	protected:
		core::TAuto<ISceneManager> Manager;
		core::TAuto<graphics::IGraphics> G;
		core::TAuto<graphics::IGraphicsCacher> Cacher;
		core::TAuto<INodeCamera> Camera;
	};
	
};

#endif

