#ifndef __BASE_I_TEXTURE_H__
#define __BASE_I_TEXTURE_H__

#include "model/TGeometry.h"

namespace engine{

	class ITexture : public virtual core::IRef
	{
	public:
		virtual const model::Sizei &getSize() = 0;
	};
	
};

#endif

