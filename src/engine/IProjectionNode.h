#ifndef __BASE_I_PROJECTION_NODE_H__
#define __BASE_I_PROJECTION_NODE_H__

#include "IControlNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IProjectionNode : public virtual IControlNode
	{
	public:
		virtual void setRegion(const model::Sizef &siz) = 0;
		virtual const model::Sizef &getRegion() = 0;
	};
	
};

#endif

