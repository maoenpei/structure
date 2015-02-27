#ifndef __BASE_CONTROL_NODE_H__
#define __BASE_CONTROL_NODE_H__

#include "IControlNode.h"
#include "CSceneNode.h"
#include "core/TAuto.h"

namespace engine{

	class CControlNode : public CSceneNode, public virtual IControlNode
	{
	public:
		virtual void acceptNode(ISceneNode *node);
		virtual ISceneNode *getAcceptNode();
		
		virtual void draw();

		CControlNode(view::IPlatform *platform);
		
	protected:
		core::TAuto<ISceneNode> AcceptNode;
	};
	
};

#endif

