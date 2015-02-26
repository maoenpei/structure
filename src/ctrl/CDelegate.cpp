

#include "CDelegate.h"
#include "core/IRegistry.h"
#include "core/TConstructor.h"
#include "engine/CSceneNode.h"
#include "view/IPlatform.h"

class TestNode : public engine::CSceneNode
{
public:
	virtual void draw()
	{
	}

	TestNode(view::IPlatform *platform)
		: CSceneNode(platform)
	{
	}
};

namespace ctrl{

CDelegate::CDelegate()
{
}

void CDelegate::onInitialized(view::IPlatform *platform)
{
	platform->getSceneManager()->changeRootNode(new TestNode(platform));
}

void CDelegate::onReadytoQuit()
{
}

};

__construct_global(DELEGATE_DEFAULT, {
	core::IRegistry *registry = getRegistry();
	registry->regist(new ctrl::CDelegate(), DELEGATE_NAME);
});


