#ifndef __BASE_RECTANGLE_NODE_H__
#define __BASE_RECTANGLE_NODE_H__

#include "CSceneNode.h"
#include "IRectangleNode.h"
#include "model/TGeometry.h"
#include "graphics/TAffine.h"

namespace engine{

	class CRectangleNode : public CSceneNode, public virtual IRectangleNode
	{
	public:
		virtual const model::Sizei &getSize();
		virtual void setSize(const model::Sizei &siz);
		
		virtual void setAnchorPoint(const model::Sizef &anchor);
		virtual const model::Sizef &getAnchorPoint();

		virtual void transform();

		CRectangleNode(view::IPlatform *platform);

	protected:
		model::Sizei RectSize;
		model::Sizef RectAnchor;
		graphics::TAffinef RectAffine;
		bool RectAffineDirty;
	};
	
};

#endif

