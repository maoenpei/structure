

#include "CProjectionNode.h"

namespace engine{

CProjectionNode::CProjectionNode(view::IPlatform *platform)
	: CGatherNode(platform)
{
}

void CProjectionNode::setRegion(const model::Sizef &siz)
{
	Siz = siz;
	Affine.v[0] = 2.f / siz.w;
	Affine.v[3] = 2.f / siz.h;
	Affine.v[4] = -1;
	Affine.v[5] = -1;
}

const model::Sizef &CProjectionNode::getRegion()
{
	return Siz;
}

void CProjectionNode::draw()
{
	// 2d projection must be the formmer projection, so no push and pop to save a node
	//Transformer->push();
	Transformer->setMode(graphics::TransformMode_2D);
	Transformer->contact(Affine);
	CGatherNode::draw();
	//Transformer->pop();
}

};


