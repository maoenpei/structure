

#include "CSceneNode.h"
#include "core/IRegistry.h"
#include "INodeCamera.h"
#include "view/IPlatform.h"

namespace engine{

CSceneNode::CSceneNode(view::IPlatform *platform)
{
	Manager = platform->getSceneManager();
	G = platform->getGraphics();
	Cacher = platform->getCacher();
}

INodeCamera *CSceneNode::getCamera()
{
	return Camera;
}

void CSceneNode::draw()
{
	graphics::ITransformer *trans = G->getTransformer();
	trans->push();
	Camera->dispose(trans);
	raw_draw();
	trans->pop();
}

void CSceneNode::raw_draw()
{
}

};


