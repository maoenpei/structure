#ifndef __BASE_SCENE_NODE_H__
#define __BASE_SCENE_NODE_H__

#include "ISceneNode.h"
#include "core/CRefObject.h"
#include "ISceneManager.h"
#include "graphics/IGraphics.h"
#include "graphics/IGraphicsCacher.h"
#include "core/TAuto.h"
#include "view/IPlatform.h"
#include "graphics/IShaderDrawer.h"

namespace engine{

	class CSceneNode : public core::CRefObject, public virtual ISceneNode
	{
	public:
		virtual INodeCamera *getCamera();
		virtual void draw();

		virtual void transform();
		virtual void raw_draw();

		CSceneNode(view::IPlatform *platform);

	protected:
		core::TAuto<graphics::IGraphics> G;
		core::TAuto<graphics::IGraphicsCacher> Cacher;
		core::TAuto<graphics::ITransformer> Transformer;
		
		core::TAuto<INodeCamera> Camera;
		core::TAuto<graphics::IShaderDrawer> Drawer;
	};
	
};

#endif

