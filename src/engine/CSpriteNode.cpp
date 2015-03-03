

#include "CSpriteNode.h"
#include "graphics/IShaderProgram.h"
#include "core/TUtils.h"
#include "CNodeCamera.h"

namespace engine{

static const char spriteVertexShader[] = 
"attribute vec2 in_pos;\n"
"attribute vec2 in_tex;\n"
"uniform vec2 uni_trans[3];\n"
"varying vec2 var_tex_coord;\n"
"void main(){\n"
	"gl_Position = vec4(\n"
		"in_pos.x*uni_trans[0].x+in_pos.y*uni_trans[1].x+uni_trans[2].x,\n"
		"in_pos.x*uni_trans[0].y+in_pos.y*uni_trans[1].y+uni_trans[2].y, 0, 1);\n"
	"var_tex_coord = in_tex;\n"
"}\n"
;

static const char spriteFragShader[] = 
"uniform sampler2D uni_tex_id;\n"
"uniform vec4 uni_color;\n"
"varying vec2 var_tex_coord;\n"
"void main(){\n"
	"vec4 col = texture2D(uni_tex_id, var_tex_coord);"
	"gl_FragColor = col * uni_color;\n"
"}\n"
;

CSpriteNode::CSpriteNode(view::IPlatform *platform, const char *img_path)
	: CRectangleNode(platform)
	, UniqueColor(1, 1, 1, 1)
{
	Camera = new engine::CNodeCamera();
	Texture = Cacher->cacheTexture(img_path, img_path);
	if (Texture){
		RectSize = Texture->getSize();
		
		graphics::IShaderProgram *program = Cacher->cacheProgram(spriteVertexShader, spriteFragShader, "uni_trans", "CSpriteNodeShader");
		program->createDrawer(Drawer);

		/*
		* 2-3
		* |\|
		* 0-1
		* order: 0-1-2, 1-3-2
		*/
		Datas[0].pt.x = 0;
		Datas[0].pt.y = 0;
		Datas[1].pt.x = (float)RectSize.w;
		Datas[1].pt.y = 0;
		Datas[2].pt.x = 0;
		Datas[2].pt.y = (float)RectSize.h;
		Datas[3].pt.x = (float)RectSize.w;
		Datas[3].pt.y = (float)RectSize.h;
		Datas[0].tex.u = 0;
		Datas[0].tex.v = 1;
		Datas[1].tex.u = 1;
		Datas[1].tex.v = 1;
		Datas[2].tex.u = 0;
		Datas[2].tex.v = 0;
		Datas[3].tex.u = 1;
		Datas[3].tex.v = 0;
		Indexs[0] = 0;
		Indexs[1] = 1;
		Indexs[2] = 2;
		Indexs[3] = 1;
		Indexs[4] = 3;
		Indexs[5] = 2;
		
		unsigned int l;
		l = program->getAttributeIndex("in_pos");
		Drawer->setAttributeValue(l, beoffset(SPRITE_DATA, pt), 2, SIG_FLOAT);
		l = program->getAttributeIndex("in_tex");
		Drawer->setAttributeValue(l, beoffset(SPRITE_DATA, tex), 2, SIG_FLOAT);
		Drawer->setAttributeData(Datas, 4, sizeof(Datas[0]));
		Drawer->setIndexs(Indexs, 6, SIG_USHORT);

		int texPos = 0;
		Drawer->setTexture(Texture, texPos);
		l = program->getUniformIndex("uni_tex_id");
		Drawer->setUniformValue(l, &texPos, 1, SIG_INT);
		ColorDataId = program->getUniformIndex("uni_color");
		Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);

	}
}

void CSpriteNode::setSize(const model::Sizei &siz)
{
	CRectangleNode::setSize(siz);
	Datas[1].pt.x = (float)RectSize.w;
	Datas[2].pt.y = (float)RectSize.h;
	Datas[3].pt.x = (float)RectSize.w;
	Datas[3].pt.y = (float)RectSize.h;
	Drawer->updateAttributeData(Datas, 1, 3);
}

void CSpriteNode::attachColor(const model::Color3f &color)
{
	UniqueColor = color;
	Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);
}

void CSpriteNode::attachColor(const model::Color4f &color)
{
	UniqueColor = color;
	Drawer->setUniformValue(ColorDataId, &UniqueColor, 1, SIG_VEC4);
}

};


