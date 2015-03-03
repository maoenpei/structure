#ifndef __BASE_I_RECTANGE_NODE_H__
#define __BASE_I_RECTANGE_NODE_H__

#include "ISceneNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IRectangleNode : public virtual ISceneNode
	{
	public:
		virtual const model::Sizei &getSize() = 0;
		virtual void setSize(const model::Sizei &siz) = 0;
		
		virtual void setAnchorPoint(const model::Sizef &anchor) = 0;
		virtual const model::Sizef &getAnchorPoint() = 0;
	};
	
};

#endif

