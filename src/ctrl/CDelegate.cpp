

#include "CDelegate.h"
#include "core/IRegistry.h"
#include "core/TConstructor.h"
#include "engine/CSceneNode.h"
#include "view/IPlatform.h"
#include "graphics/IShaderProgram.h"
#include "engine/CNodeCamera.h"
#include "engine/CProjectionNode.h"
#include "engine/CSpriteNode.h"
#include "engine/CColoredPanelNode.h"

namespace ctrl{

CDelegate::CDelegate()
{
}

void CDelegate::onInitialized(view::IPlatform *platform)
{
	engine::CColoredPanelNode *node2 = new engine::CColoredPanelNode(platform, model::Sizei(128, 128), model::Color4f(1, 0, 0, 1));
	engine::CSpriteNode *node = new engine::CSpriteNode(platform, "small_arrow.png");
//	node2->attachColor(model::Color3f(1, 0, 0));
//	node2->setAnchorPoint(model::Sizef(0.5f, 0.5f));
	engine::INodeCamera *camera = node2->getCamera();
	camera->move(64, 64);
	camera->scale(0.5f,1);
	camera->rotate(3.1415926f/6);
	engine::CProjectionNode *project = new engine::CProjectionNode(platform);
	project->setRegion(model::Sizef(800.f, 480.f));
	project->addChild(node2, -1);
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


