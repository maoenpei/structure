#ifndef __BASE_COLORED_PANEL_NODE_H__
#define __BASE_COLORED_PANEL_NODE_H__

#include "CRectangleNode.h"
#include "IColoredNode.h"
#include "TAttribData.h"

namespace engine{

	class CColoredPanelNode : public CRectangleNode, public virtual IColoredNode
	{
	public:
		virtual void setSize(const model::Sizei &siz);
		
		virtual void attachColor(const model::Color3f &color);
		virtual void attachColor(const model::Color4f &color);

		CColoredPanelNode(view::IPlatform *platform, const model::Sizei &siz, const model::Color4f &color);

	private:
		model::Color4f UniqueColor;

		POS2D<float> Datas[4];
		unsigned short Indexs[6];
		unsigned int ColorDataId;
	};
	
};

#endif

