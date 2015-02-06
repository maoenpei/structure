#ifndef __BASE_I_TRANSFORMER_H__
#define __BASE_I_TRANSFORMER_H__

#include "core/IRef.h"
#include "TAffine.h"
#include "TMatrix.h"

namespace engine{

	enum{
		TransformMode_2D,
		TransformMode_3D,
		TransformMode_Max
	};
	
	class ITransformer : public virtual core::IRef
	{
	public:
		virtual void setMode(unsigned int mode) = 0;

		virtual void push();
		virtual void pop();
		virtual void contact(const TAffinef &aff);
		virtual void load(const TAffinef &aff);
		virtual void contact(const TMatrixf &mat);
		virtual void load(const TMatrixf &mat);
	};
	
};

#endif

