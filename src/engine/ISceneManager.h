#ifndef __BASE_I_SCENE_MANAGER_H__
#define __BASE_I_SCENE_MANAGER_H__

#include "core/IRef.h"

namespace engine{

	class ISceneNode;
	class ISceneManager : public virtual core::IRef
	{
	public:
		virtual void setRootNode(ISceneNode *node) = 0;
		virtual ISceneNode *getRootNode() = 0;

		virtual void draw() = 0;
	};
	
};

#endif

