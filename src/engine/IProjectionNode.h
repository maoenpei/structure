#ifndef __BASE_I_PROJECTION_NODE_H__
#define __BASE_I_PROJECTION_NODE_H__

#include "IControlNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IProjectionNode : public virtual IControlNode
	{
	public:
		virtual void setVolume(const model::Volumef &vol) = 0;
		virtual const model::Volumef &getVolume() = 0;
	};
	
};

#endif

