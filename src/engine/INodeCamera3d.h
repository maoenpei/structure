#ifndef __BASE_I_NODE_CAMERA_3D_H__
#define __BASE_I_NODE_CAMERA_3D_H__

#include "INodeCamera.h"
#include "model/TGeometry.h"

namespace engine{

	class INodeCamera3d : public virtual INodeCamera
	{
	public:
		virtual void move(const model::Vectorf &dist) = 0;
		virtual void scale(float sx, float sy, float sz) = 0;
		virtual void rotate(const model::Vectorf &axis, float sita) = 0;
	};
	
};

#endif

