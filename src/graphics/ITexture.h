#ifndef __BASE_I_TEXTURE_H__
#define __BASE_I_TEXTURE_H__

#include "core/IRef.h"
#include "model/TGeometry.h"

namespace graphics{

	class ITexture : public virtual core::IRef
	{
	public:
		virtual const model::Sizei &getSize() = 0;
	};
	
};

#endif

