#ifndef __BASE_I_GRAPHICS_CACHER_H__
#define __BASE_I_GRAPHICS_CACHER_H__

#include "core/IRef.h"
#include "ITexture.h"

namespace engine{

	class IGraphicsCacher : public virtual core::IRef
	{
	public:
		virtual ITexture *cacheTexture(const char *path, const char *name) = 0;
		virtual void removeTexture(const char *name) = 0;
	};
	
};

#endif


