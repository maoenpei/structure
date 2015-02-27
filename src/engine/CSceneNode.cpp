

#include "CSceneNode.h"
#include "core/IRegistry.h"
#include "INodeCamera.h"
#include "view/IPlatform.h"

namespace engine{

CSceneNode::CSceneNode(view::IPlatform *platform)
{
	G = platform->getGraphics();
	Transformer = G->getTransformer();
}

INodeCamera *CSceneNode::getCamera()
{
	return Camera;
}

void CSceneNode::draw()
{
	Transformer->push();
	Camera->dispose(Transformer);
	this->raw_draw();
	Transformer->pop();
}

void CSceneNode::raw_draw()
{
}

};


