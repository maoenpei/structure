#ifndef __BASE_I_COLORED_NODE_H__
#define __BASE_I_COLORED_NODE_H__

#include "ISceneNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IColoredNode : public virtual ISceneNode
	{
	public:
		virtual void attachColor(const model::Color3f &color) = 0;
		virtual void attachColor(const model::Color4f &color) = 0;
	};
	
};

#endif

