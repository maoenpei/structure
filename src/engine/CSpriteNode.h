#ifndef __BASE_SPRITE_NODE_H__
#define __BASE_SPRITE_NODE_H__

#include "CColoredNode.h"
#include "IRectangeNode.h"
#include "model/TGeometry.h"
#include "core/TAuto.h"
#include "graphics/ITexture.h"
#include "TAttribData.h"

namespace engine{

	class CSpriteNode : public CColoredNode, public virtual IRectangeNode
	{
	public:
		virtual const model::Sizei &getSize();
		virtual void setAnchorPoint(const model::Sizef &anchor);
		virtual const model::Sizef &getAnchorPoint();
		
		virtual void attachColor(const model::Color3f &color);
		virtual void attachColor(const model::Color4f &color);

		virtual void raw_draw();
		
		CSpriteNode(view::IPlatform *platform, const char *img_path);

	private:
		core::TAuto<graphics::ITexture> Texture;
		model::Sizef Anchor;
		
		bool DataDirty;
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

