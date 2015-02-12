#ifndef __BASE_I_SCENE_MANAGER_H__
#define __BASE_I_SCENE_MANAGER_H__

#include "core/IRef.h"
#include "core/TAuto.h"

namespace engine{

	class ISceneNode;
	class ISceneManager : public virtual core::IRef
	{
	public:
		virtual void changeRootNode(ISceneNode *node) = 0;

		virtual void doDraw() = 0;
	};
	
};

#endif

