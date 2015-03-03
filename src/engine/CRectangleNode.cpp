

#include "CRectangleNode.h"

namespace engine{

CRectangleNode::CRectangleNode(view::IPlatform *platform)
	: CSceneNode(platform)
	, RectAffineDirty(true)
{
}

const model::Sizei &CRectangleNode::getSize()
{
	return RectSize;
}

void CRectangleNode::setSize(const model::Sizei &siz)
{
	RectSize = siz;
	RectAffineDirty = true;
}

const model::Sizef &CRectangleNode::getAnchorPoint()
{
	return RectAnchor;
}

void CRectangleNode::setAnchorPoint(const model::Sizef &anchor)
{
	RectAnchor = anchor;
	RectAffineDirty = true;
}

void CRectangleNode::transform()
{
	if (RectAffineDirty){
		RectAffineDirty = false;
		RectAffine.v[4] = -RectSize.w * RectAnchor.w;
		RectAffine.v[5] = -RectSize.h * RectAnchor.h;
	}
	CSceneNode::transform();
	Transformer->contact(RectAffine);
}

};


