

#include "CSceneManager.h"
#include "ISceneNode.h"

namespace engine{

CSceneManager::CSceneManager(view::IPlatform *platform)
{
}

void CSceneManager::changeRootNode(ISceneNode * node)
{
	RootNode = node;
}

void CSceneManager::doDraw()
{
	RootNode->draw();
}


};


