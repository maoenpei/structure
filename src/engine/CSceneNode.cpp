

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
	if (Camera){
		Transformer->push();
		Camera->dispose(Transformer);
	}
	this->raw_draw();
	if (Camera){
		Transformer->pop();
	}
}

void CSceneNode::raw_draw()
{
	if (Drawer){
		G->pipeline(Drawer);
	}
}

};


