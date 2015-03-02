#ifndef __BASE_SPRITE_NODE_H__
#define __BASE_SPRITE_NODE_H__

#include "CSceneNode.h"
#include "IColoredNode.h"
#include "model/TGeometry.h"

namespace engine{

	class CSpriteNode : public CSceneNode, public virtual IColoredNode
	{
	public:
		virtual void attachColor(const model::Color3f &color);
		virtual void attachColor(const model::Color4f &color);
		
		CSpriteNode(view::IPlatform *platform);

	private:
		
	};
	
};

#endif

