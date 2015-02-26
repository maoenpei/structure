#ifndef __BASE_I_SCENE_NODE_H__
#define __BASE_I_SCENE_NODE_H__

#include "core/IRef.h"
#include "ISceneManager.h"
#include "INodeCamera.h"

namespace engine{

	class ISceneNode : public virtual core::IRef
	{
	public:
		virtual void draw() = 0;

		virtual INodeCamera *getCamera() = 0;
	};
	
};

#endif

