#ifndef __BASE_I_COLORED_NODE_H__
#define __BASE_I_COLORED_NODE_H__

#include "ISceneNode.h"

namespace engine{

	class IColoredNode : public virtual ISceneNode
	{
	public:
		virtual void attachColor(float r, float g, float b) = 0;
		virtual void attachColor(float r, float g, float b, float a) = 0;
	};
	
};

#endif

