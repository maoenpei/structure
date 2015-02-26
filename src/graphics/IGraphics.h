#ifndef __BASE_I_ENGINE_H__
#define __BASE_I_ENGINE_H__

#include "core/IRef.h"
#include "model/IImage.h"
#include "ITransformer.h"
#include "core/TAuto.h"

namespace graphics{
	
	class ITexture;
	class IShaderProgram;
	class IShaderDrawer;
	class IGraphics : public virtual core::IRef
	{
	public:
		virtual ITransformer *getTransformer() = 0;
		
		virtual void loadTexture(core::TAuto<ITexture> &texture, model::IImage *image) = 0;
		virtual void loadProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag) = 0;

		virtual void cleanBuffer() = 0;
		virtual void pipeline(IShaderDrawer *drawer) = 0;
	};
	
};

#endif

