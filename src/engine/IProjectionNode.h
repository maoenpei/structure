#ifndef __BASE_I_PROJECTION_NODE_H__
#define __BASE_I_PROJECTION_NODE_H__

#include "ISceneNode.h"
#include "TGeometry.h"

namespace engine{

	class IProjectionNode : public virtual ISceneNode
	{
	public:
		virtual void setVolume(const Volumef &vol) = 0;
		virtual const Volumef &getVolume() = 0;
	};
	
};

#endif

