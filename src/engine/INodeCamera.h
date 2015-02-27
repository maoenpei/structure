#ifndef __BASE_I_NODE_CAMERA_H__
#define __BASE_I_NODE_CAMERA_H__

#include "core/IRef.h"
#include "graphics/ITransformer.h"

namespace engine{

	class INodeCamera : public virtual core::IRef
	{
	public:
		// dispose transformation to graphics
		virtual void dispose(graphics::ITransformer * trans) = 0;

		virtual void identity() = 0;
		virtual void move(float mx, float my) = 0;
		virtual void scale(float sx, float sy) = 0;
		virtual void rotate(float sita) = 0;
	};
	
};

#endif


