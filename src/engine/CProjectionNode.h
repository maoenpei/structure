#ifndef __BASE_PROJECTION_NODE_H__
#define __BASE_PROJECTION_NODE_H__

#include "IProjectionNode.h"
#include "CGatherNode.h"
#include "graphics/TAffine.h"

namespace engine{

	class CProjectionNode : public CGatherNode, public virtual IProjectionNode
	{
	public:
		virtual void setRegion(const model::Sizef &siz);
		virtual const model::Sizef &getRegion();

		virtual void draw();

		CProjectionNode(view::IPlatform *platform);

	private:
		model::Sizef Siz;
		graphics::TAffinef Affine;
	};
	
};

#endif

