

#include "CSceneNode.h"
#include "core/IRegistry.h"
#include "INodeCamera.h"
#include "view/IPlatform.h"

namespace engine{

CSceneNode::CSceneNode(view::IPlatform *platform)
{
	G = platform->getGraphics();
	Cacher = platform->getCacher();
	Transformer = G->getTransformer();
}

INodeCamera *CSceneNode::getCamera()
{
	return Camera;
}

void CSceneNode::draw()
{
	Transformer->push();
	this->transform();
	this->raw_draw();
	Transformer->pop();
}

void CSceneNode::transform()
{
	if (Camera){
		Camera->dispose(Transformer);
	}
}

void CSceneNode::raw_draw()
{
	if (Drawer){
		G->pipeline(Drawer);
	}
}

};


