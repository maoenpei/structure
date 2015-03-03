

#include "CDelegate.h"
#include "core/IRegistry.h"
#include "core/TConstructor.h"
#include "engine/CSceneNode.h"
#include "view/IPlatform.h"
#include "graphics/IShaderProgram.h"
#include "engine/CNodeCamera.h"
#include "engine/CProjectionNode.h"
#include "engine/CSpriteNode.h"

namespace ctrl{

CDelegate::CDelegate()
{
}

void CDelegate::onInitialized(view::IPlatform *platform)
{
	engine::CSpriteNode *node = new engine::CSpriteNode(platform, "small_arrow.png");
	node->attachColor(model::Color3f(1, 0, 0));
	node->setAnchorPoint(model::Sizef(0.5f, 0.5f));
	engine::INodeCamera *camera = node->getCamera();
	camera->move(100, 100);
	engine::CProjectionNode *project = new engine::CProjectionNode(platform);
	project->setRegion(model::Sizef(800.f, 480.f));
	project->addChild(node, -1);
	platform->getSceneManager()->changeRootNode(project);
}

void CDelegate::onReadytoQuit()
{
}

};

__construct_global(DELEGATE_DEFAULT, {
	core::IRegistry *registry = getRegistry();
	registry->regist(new ctrl::CDelegate(), DELEGATE_NAME);
});


