#ifndef __BASE_I_GATHER_NODE_H__
#define __BASE_I_GATHER_NODE_H__

#include "ISceneNode.h"

namespace engine{

	/* index can be 0~(num-1) or NODE_INDEX_LAST */
	class IGatherNode : public virtual ISceneNode
	{
	public:
		virtual void addChild(ISceneNode *node, int index) = 0;
		virtual void removeChild(int index) = 0;
		virtual int getChildrenNum() = 0;
		virtual ISceneNode *getChild(int index) = 0;
	};
	
};

#define NODE_INDEX_LAST			(-1)

#endif

