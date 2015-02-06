#ifndef __BASE_SCENE_NODE_H__
#define __BASE_SCENE_NODE_H__

#include "ISceneNode.h"
#include "core/CRefObject.h"
#include "ISceneManager.h"
#include "IGraphics.h"
#include "IGraphicsCacher.h"
#include "core/TAuto.h"

namespace engine{

	class CSceneNode : public core::CRefObject, public ISceneNode
	{
	public:
		virtual INodeCamera *getCamera();

		CSceneNode();

	protected:
		core::TAuto<ISceneManager> Manager;
		core::TAuto<IGraphics> G;
		core::TAuto<IGraphicsCacher> Cacher;
		core::TAuto<INodeCamera> Camera;
	};
	
};

#endif

