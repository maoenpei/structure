

#include "CDelegate.h"
#include "core/IRegistry.h"
#include "core/TConstructor.h"
#include "engine/CSceneNode.h"
#include "view/IPlatform.h"
#include "graphics/IShaderProgram.h"
#include "graphics/IShaderDrawer.h"
#include "engine/CNodeCamera.h"
#include "engine/CProjectionNode.h"

const char vertexShader[] = 
"attribute vec2 in_pos;"
"uniform vec2 uni_trans[3];"
"void main(){"
"	gl_Position = vec4("
"in_pos.x*uni_trans[0].x+in_pos.y*uni_trans[1].x+uni_trans[2].x, "
"in_pos.x*uni_trans[0].y+in_pos.y*uni_trans[1].y+uni_trans[2].y, 0, 1);"
"}"
;

const char fragShader[] = 
"void main(){"
"	gl_FragColor = vec4(1.0, 0, 0, 1.0);"
"}"
;

struct POSITION
{
	float x,y;
	POSITION(float _x, float _y) : x(_x), y(_y){}
	POSITION() : x(0), y(0){}
};

class TestNode : public engine::CSceneNode
{
public:
	virtual void draw()
	{
		Transformer->push();
		Camera->dispose(Transformer);
		G->pipeline(drawer);
		Transformer->pop();
	}

	TestNode(view::IPlatform *platform)
		: CSceneNode(platform)
	{
		pos[0] = POSITION(0.f, 0.f);
		pos[1] = POSITION(200.f, 0.f);
		pos[2] = POSITION(0.f, 200.f);
		pos[3] = POSITION(200.f, 200.f);
		idxs[0] = 0;
		idxs[1] = 1;
		idxs[2] = 2;
		idxs[3] = 1;
		idxs[4] = 3;
		idxs[5] = 2;
		G->loadProgram(program, vertexShader, fragShader);
		program->setTransformName("uni_trans");
		l = program->getAttributeIndex("in_pos");
		program->createDrawer(drawer);
		drawer->setAttributeValue(l, 0, 2, SIG_FLOAT);
		drawer->setAttributeData(&pos, 4, sizeof(pos[0]));
		drawer->setIndexs(idxs, 6, SIG_USHORT);

		Camera = new engine::CNodeCamera();
		engine::INodeCamera * camera = getCamera();
		camera->rotate(3.141592653f / 6);
//		camera->scale(1/400.f, 1/240.f);
//		camera->move(-1, -1);
	}
	POSITION pos[4];
	unsigned short idxs[6];
	core::TAuto<graphics::IShaderProgram> program;
	core::TAuto<graphics::IShaderDrawer> drawer;
	unsigned int l;
};

namespace ctrl{

CDelegate::CDelegate()
{
}

void CDelegate::onInitialized(view::IPlatform *platform)
{
	TestNode *node = new TestNode(platform);
	engine::CProjectionNode *project = new engine::CProjectionNode(platform);
	project->acceptNode(node);
	project->setRegion(model::Sizef(800.f, 480.f));
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


