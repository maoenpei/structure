#ifndef __BASE_I_GRAPHICS_CACHER_H__
#define __BASE_I_GRAPHICS_CACHER_H__

#include "core/IRef.h"
#include "ITexture.h"
#include "IShaderProgram.h"

namespace graphics{
	
	class IGraphicsCacher : public virtual core::IRef
	{
	public:
		virtual ITexture *cacheTexture(const char *path, const char *name) = 0;
		virtual ITexture *findTexture(const char *name) = 0;
		virtual void removeTexture(const char *name) = 0;

		virtual IShaderProgram *cacheProgram(const char *vertex, const char *frag, const char *transName, const char *name) = 0;
		virtual IShaderProgram *findProgram(const char *name) = 0;
		virtual void removeProgram(const char *name) = 0;
	};
	
};

#endif


