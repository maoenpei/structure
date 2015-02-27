#ifndef __BASE_I_GATHER_NODE_H__
#define __BASE_I_GATHER_NODE_H__

#include "ISceneNode.h"

namespace engine{

	class IGatherNode : public virtual ISceneNode
	{
	public:
		/* -1 means the last one */
		virtual void addChild(ISceneNode *node, int index) = 0;
		virtual void removeChild(int index) = 0;
		virtual int getChildNum() = 0;
		virtual ISceneNode *getChild(int index) = 0;
	};
	
};

#endif

