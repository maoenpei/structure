#ifndef __BASE_COLORED_NODE_H__
#define __BASE_COLORED_NODE_H__

#include "CSceneNode.h"
#include "IColoredNode.h"

namespace engine{

	class CColoredNode : public CSceneNode, public virtual IColoredNode
	{
	public:
		virtual void attachColor(const model::Color3f &color);
		virtual void attachColor(const model::Color4f &color);
		
		CColoredNode(view::IPlatform *platform);

	protected:
		model::Color4f UniqueColor;
	};
	
};

#endif

