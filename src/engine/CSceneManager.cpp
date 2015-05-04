

#include "CSceneManager.h"
#include "ISceneNode.h"

namespace engine{

CSceneManager::CSceneManager(view::IPlatform *platform)
{
	G = platform->getGraphics();
}

void CSceneManager::changeRootNode(ISceneNode * node)
{
	RootNode = node;
}

void CSceneManager::doDraw()
{
	G->clear();
	RootNode->draw();
}


};


