

#include "CSceneNode.h"
#include "core/IRegistry.h"
#include "INodeCamera.h"

namespace engine{

CSceneNode::CSceneNode()
{
	view::IPlatform *platform = dynamic_cast<view::IPlatform *>(getRegistry()->find(IPLATFORM_NAME));
	Manager = platform->getSceneManager();
	G = platform->getGraphics();
	Cacher = platform->getCacher();
}

INodeCamera *CSceneNode::getCamera()
{
	return Camera;
}

};


