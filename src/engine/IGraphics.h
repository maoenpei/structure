#ifndef __BASE_I_ENGINE_H__
#define __BASE_I_ENGINE_H__

#include "core/IRef.h"
#include "model/IImage.h"
#include "ITransformer.h"

namespace engine{
	
	class ITexture;
	class IShaderProgram;
	class IShaderDrawer;
	class IGraphics : public virtual core::IRef
	{
	public:
		virtual ITransformer *getTransformer() = 0;
		
		virtual ITexture *loadTexture(model::IImage *image) = 0;
		virtual IShaderProgram *loadProgram(const char *vertex, const char *frag) = 0;
		
		virtual void pipeline(IShaderDrawer *drawer, int n) = 0;
	};
	
};

#endif

