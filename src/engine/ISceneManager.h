#ifndef __BASE_I_SCENE_MANAGER_H__
#define __BASE_I_SCENE_MANAGER_H__

#include "core/IRef.h"
#include "ITexture.h"
#include "core/TAuto.h"
#include "IGraphics.h"

namespace engine{

	class ISceneNode;
	class ISceneManager : public virtual core::IRef
	{
	public:
		virtual void setGraphics(IGraphics *gi) = 0;
		virtual IGraphics *getGraphics() = 0;
		
		virtual ITexture *cacheTexture(const char *path, const char *name) = 0;
		virtual void removeTexture(const char *name) = 0;

		virtual void setRootNode(ISceneNode *node) = 0;
		virtual ISceneNode *getRootNode() = 0;

		virtual void doDraw() = 0;
	};
	
};

#endif

