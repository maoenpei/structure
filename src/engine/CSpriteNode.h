#ifndef __BASE_SPRITE_NODE_H__
#define __BASE_SPRITE_NODE_H__

#include "CRectangleNode.h"
#include "IColoredNode.h"
#include "model/TGeometry.h"
#include "core/TAuto.h"
#include "graphics/ITexture.h"
#include "TAttribData.h"

namespace engine{

	class CSpriteNode : public CRectangleNode, public virtual IColoredNode
	{
	public:
		virtual void setSize(const model::Sizei &siz);
		
		virtual void attachColor(const model::Color3f &color);
		virtual void attachColor(const model::Color4f &color);
		
		CSpriteNode(view::IPlatform *platform, const char *img_path);

	private:
		core::TAuto<graphics::ITexture> Texture;
		model::Color4f UniqueColor;
		
		struct SPRITE_DATA{
			POS2D<float> pt;
			TEX2D<float> tex;
		};
		SPRITE_DATA Datas[4];
		unsigned short Indexs[6];
		unsigned int ColorDataId;
	};
	
};

#endif

