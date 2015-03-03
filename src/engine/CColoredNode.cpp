

#include "CColoredNode.h"

namespace engine{

CColoredNode::CColoredNode(view::IPlatform *platform)
	: CSceneNode(platform)
{
}

void CColoredNode::attachColor(const model::Color3f &color)
{
	UniqueColor.r = color.r;
	UniqueColor.g = color.g;
	UniqueColor.b = color.b;
	UniqueColor.a = 1;
}

void CColoredNode::attachColor(const model::Color4f &color)
{
	UniqueColor = color;
}

};

