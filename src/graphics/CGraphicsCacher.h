#ifndef __BASE_GRAPHICS_CACHER_H__
#define __BASE_GRAPHICS_CACHER_H__

#include "IGraphicsCacher.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include "IGraphics.h"
#include <map>
#include <string>

namespace graphics{

	class CGraphicsCacher : public core::CRefObject, public virtual IGraphicsCacher
	{
	public:
		virtual ITexture *cacheTexture(const char *path, const char *name);
		virtual ITexture *findTexture(const char *name);
		virtual void removeTexture(const char *name);

		virtual IShaderProgram *cacheProgram(const char *vertex, const char *frag, const char *transName, const char *name);
		virtual IShaderProgram *findProgram(const char *name);
		virtual void removeProgram(const char *name);

		CGraphicsCacher(IGraphics *graph);

	private:
		core::TAuto<IGraphics> G;
		std::map<std::string, core::TAuto<ITexture> > Textures;
		std::map<std::string, core::TAuto<IShaderProgram> > Programs;
	};
	
};

#endif

