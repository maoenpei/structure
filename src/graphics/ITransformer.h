#ifndef __BASE_I_TRANSFORMER_H__
#define __BASE_I_TRANSFORMER_H__

#include "core/IRef.h"
#include "TAffine.h"
#include "TMatrix.h"

namespace graphics{

	enum{
		TransformMode_2D,
		TransformMode_3D,
		TransformMode_Max
	};
	
	class ITransformer : public virtual core::IRef
	{
	public:
		virtual void setMode(unsigned int mode) = 0;
		virtual void *getMode(unsigned int &mode) = 0;

		virtual void push() = 0;
		virtual void pop() = 0;
		virtual void contact(const TAffinef &aff) = 0;
		virtual void load(const TAffinef &aff) = 0;
		virtual void get(TAffinef &aff) = 0;
		virtual void contact(const TMatrixf &mat) = 0;
		virtual void load(const TMatrixf &mat) = 0;
		virtual void get(TMatrixf &mat) = 0;
	};
	
};

#endif

