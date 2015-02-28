#ifndef __BASE_GATHER_NODE_H__
#define __BASE_GATHER_NODE_H__

#include "IGatherNode.h"
#include "CSceneNode.h"
#include <vector>

namespace engine{

	class CGatherNode : public CSceneNode, public virtual IGatherNode
	{
	public:
		virtual void addChild(ISceneNode *node, int index);
		virtual void removeChild(int index);
		virtual int getChildNum();
		virtual ISceneNode *getChild(int index);

		virtual void raw_draw();

		CGatherNode(view::IPlatform *platform);

	private:
		std::vector<core::TAuto<ISceneNode> > Children;
	};
	
};

#endif

