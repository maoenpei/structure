#ifndef __GL_GRAPHICS_H__
#define __GL_GRAPHICS_H__

#include "IGraphics.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <glew.h>

namespace engine{

	class GLGraphics : public core::CRefObject, public virtual IGraphics
	{
	public:
		virtual ITransformer *getTransformer();
		
		virtual ITexture *loadTexture(model::IImage *image);
		virtual IShaderProgram *loadProgram(const char *vertex, const char *frag);
		
		virtual void pipeline(IShaderDrawer *drawer, int n);

		GLGraphics();

	private:
		core::TAuto<ITransformer> Transformer;
		
	};
	
};

#endif

