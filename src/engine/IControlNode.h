#ifndef __BASE_I_CONTROL_NODE_H__
#define __BASE_I_CONTROL_NODE_H__

#include "ISceneNode.h"

namespace engine{

	class IControlNode : public virtual ISceneNode
	{
	public:
		virtual void acceptNode(ISceneNode *node) = 0;
		virtual ISceneNode *getAcceptNode() = 0;
	};
	
};

#endif

