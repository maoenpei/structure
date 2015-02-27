#ifndef __BASE_NODE_CAMERA_H__
#define __BASE_NODE_CAMERA_H__

#include "INodeCamera.h"
#include "core/CRefObject.h"
#include "graphics/TAffine.h"

namespace engine{

	class CNodeCamera : public core::CRefObject, public virtual INodeCamera
	{
	public:
		virtual void dispose(graphics::ITransformer * trans);

		virtual void identity();
		virtual void move(float mx, float my);
		virtual void scale(float sx, float sy);
		virtual void rotate(float sita);

	private:
		graphics::TAffinef Affine;
	};
	
};

#endif


