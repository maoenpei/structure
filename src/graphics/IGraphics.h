#ifndef __BASE_I_ENGINE_H__
#define __BASE_I_ENGINE_H__

#include "core/IRef.h"
#include "model/IImage.h"
#include "ITransformer.h"
#include "core/TAuto.h"
#include "model/TGeometry.h"

namespace graphics{
	
	class ITexture;
	class IShaderProgram;
	class IShaderDrawer;
	class IFramebuffer;
	class IGraphics : public virtual core::IRef
	{
	public:
		virtual ITransformer *getTransformer() = 0;

		virtual void createTexture(core::TAuto<ITexture> &texture, model::Sizei &siz) = 0;
		virtual void createTexture(core::TAuto<ITexture> &texture, model::IImage *image) = 0;
		virtual void createProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag) = 0;
		virtual void createBuffer(core::TAuto<IFramebuffer> &fb, const model::Sizei &siz) = 0; // create offline buffer
		
		virtual IFramebuffer *getBuffer() = 0;
		virtual void pushBuffer(IFramebuffer *buffer) = 0;
		virtual void popBuffer() = 0;

		virtual void clearBuffer() = 0;
		virtual void pipeline(IShaderDrawer *drawer) = 0;
	};
	
};

#endif

