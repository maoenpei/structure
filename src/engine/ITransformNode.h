#ifndef __BASE_I_TRANSFORM_NODE_H__
#define __BASE_I_TRANSFORM_NODE_H__

#include "ISceneNode.h"

namespace engine{

	class ITransformNode : public virtual ISceneNode
	{
	public:
		virtual void setAcceptNode(ISceneNode *node) = 0;
		virtual ISceneNode *getAcceptNode() = 0;
	};
	
};

#endif

