#ifndef __BASE_NODE_CAMERA_3D_H__
#define __BASE_NODE_CAMERA_3D_H__

#include "INodeCamera3d.h"
#include "core/CRefObject.h"
#include "graphics/TMatrix.h"

namespace engine{

	class CNodeCamera3d : public core::CRefObject, public virtual INodeCamera3d
	{
	public:
		virtual void dispose(graphics::ITransformer * trans);

		virtual void identity();
		virtual void move(float mx, float my);
		virtual void scale(float sx, float sy);
		virtual void rotate(float sita);
		
		virtual void move(const model::Vectorf &dist);
		virtual void scale(float sx, float sy, float sz);
		virtual void rotate(const model::Vectorf &axis, float sita);

	private:
		graphics::TMatrixf Matrix;
	};
	
};

#endif

