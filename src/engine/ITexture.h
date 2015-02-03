#ifndef __BASE_I_TEXTURE_H__
#define __BASE_I_TEXTURE_H__

#include "TGeometry.h"

namespace engine{

	class ITexture : public virtual core::IRef
	{
	public:
		virtual Sizei getSize() = 0;
	};
	
};

#endif

