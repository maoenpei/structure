

#include "CSceneNode.h"
#include "core/IRegistry.h"
#include "INodeCamera.h"

namespace engine{

CSceneNode::CSceneNode()
{
	SceneManager = dynamic_cast<ISceneManager *>(getRegistry()->find(REGISTRY_FUNC_NAME));
}

INodeCamera *CSceneNode::getCamera()
{
	return Camera;
}

};


