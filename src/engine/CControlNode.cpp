

#include "CControlNode.h"

namespace engine{

CControlNode::CControlNode(view::IPlatform *platform)
	: CSceneNode(platform)
{
}

void CControlNode::acceptNode(ISceneNode * node)
{
	AcceptNode = node;
}

ISceneNode *CControlNode::getAcceptNode()
{
	return AcceptNode;
}

void CControlNode::draw()
{
	if (AcceptNode){
		AcceptNode->draw();
	}
}

};

