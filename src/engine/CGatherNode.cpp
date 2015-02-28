

#include "CGatherNode.h"

namespace engine{

CGatherNode::CGatherNode(view::IPlatform *platform)
	: CSceneNode(platform)
{
}

void CGatherNode::addChild(ISceneNode * node,int index)
{
	if (index < 0){
		Children.push_back(node);
	}else{
		Children.insert(Children.begin() + index, node);
	}
}

void CGatherNode::removeChild(int index)
{
	Children.erase(Children.begin() + index);
}

int CGatherNode::getChildNum()
{
	return (int)Children.size();
}

ISceneNode *CGatherNode::getChild(int index)
{
	return Children[index];
}

void CGatherNode::raw_draw()
{
	std::vector<core::TAuto<ISceneNode> >::iterator it;
	for (it = Children.begin(); it != Children.end(); it++){
		(*it)->draw();
	}
}

};


