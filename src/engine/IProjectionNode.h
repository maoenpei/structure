#ifndef __BASE_I_PROJECTION_NODE_H__
#define __BASE_I_PROJECTION_NODE_H__

#include "ISceneNode.h"
#include "model/TGeometry.h"

namespace engine{

	class IProjectionNode : public virtual ISceneNode
	{
	public:
		virtual void setVolume(const model::Volumef &vol) = 0;
		virtual const model::Volumef &getVolume() = 0;
	};
	
};

#endif

