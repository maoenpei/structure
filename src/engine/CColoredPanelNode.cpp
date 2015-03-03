

#include "CColoredPanelNode.h"
#include "CNodeCamera.h"

namespace engine{

static const char coloredPanelVertexShader[] = 
"attribute vec2 in_pos;\n"
"uniform vec2 uni_trans[3];\n"
"void main(){\n"
	"gl_Position = vec4(\n"
		"in_pos.x*uni_trans[0].x+in_pos.y*uni_trans[1].x+uni_trans[2].x,\n"
		"in_pos.x*uni_trans[0].y+in_pos.y*uni_trans[1].y+uni_trans[2].y, 0, 1);\n"
"}\n"
;

static const char coloredPanelFragShader[] = 
"uniform vec4 uni_color;\n"
"void main(){\n"
	"gl_FragColor = uni_color;\n"
"}\n"
;

CColoredPanelNode::CColoredPanelNode(view::IPlatform *platform, const model::Sizei &siz, const model::Color4f &color)
	: CRectangleNode(platform)
	, UniqueColor(color)
{
	Camera = new engine::CNodeCamera();
	RectSize = siz;

	graphics::IShaderProgram *program = Cacher->cacheProgram(coloredPanelVertexShader, coloredPanelFragShader, "uni_trans", "CColoredPanelNodeShader");
	program->createDrawer(Drawer);

	/*
	* 2-3
	* |\|
	* 0-1
	* order: 0-1-2, 1-3-2
	*/
	Datas[0].x = 0;
	Datas[0].y = 0;
	Datas[1].x = (float)RectSize.w;
	Datas[1].y = 0;
	Datas[2].x = 0;
	Datas[2].y = (float)RectSize.h;
	Datas[3].x = (float)RectSize.w;
	Datas[3].y = (float)RectSize.h;
	Indexs[0] = 0;
	Indexs[1] = 1;
	Indexs[2] = 2;
	Indexs[3] = 1;
	Indexs[4] = 3;
	Indexs[5] = 2;
	
	unsigned int l;
	l = program->getAttributeIndex("in_pos");
	Drawer->setAttributeValue(l, 0, 2, SIG_FLOAT);
	Drawer->setAttributeData(Datas, 4, sizeof(Datas[0]));
	Drawer->setIndexs(Indexs, 6, SIG_USHORT);
	
	ColorDataId = program->getUniformIndex("uni_color");
	Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);
}

void CColoredPanelNode::setSize(const model::Sizei &siz)
{
	CRectangleNode::setSize(siz);
	Datas[1].x = (float)RectSize.w;
	Datas[2].y = (float)RectSize.h;
	Datas[3].x = (float)RectSize.w;
	Datas[3].y = (float)RectSize.h;
	Drawer->updateAttributeData(Datas, 1, 3);
}

void CColoredPanelNode::attachColor(const model::Color3f &color)
{
	UniqueColor = color;
	Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);
}

void CColoredPanelNode::attachColor(const model::Color4f &color)
{
	UniqueColor = color;
	Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);
}

};


