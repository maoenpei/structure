#ifndef __BASE_I_PROJECTION_NODE_H__
#define __BASE_I_PROJECTION_NODE_H__

#include "IGatherNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IProjectionNode : public virtual IGatherNode
	{
	public:
		virtual void setRegion(const model::Sizef &siz) = 0;
		virtual const model::Sizef &getRegion() = 0;
	};
	
};

#endif

