#ifndef __GL_GRAPHICS_H__
#define __GL_GRAPHICS_H__

#include "IGraphics.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <glew.h>
#include "GLStateCacher.h"

namespace graphics{

	class GLGraphics : public core::CRefObject, public virtual IGraphics
	{
	public:
		virtual ITransformer *getTransformer();
		
		virtual void loadTexture(core::TAuto<ITexture> &texture, model::IImage *image);
		virtual void loadProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag);

		virtual void cleanBuffer();
		virtual void pipeline(IShaderDrawer *drawer, int n);

		void initAPIs();
		GLGraphics();

	private:
		core::TAuto<ITransformer> Transformer;
		core::TAuto<GLStateCacher> StateCacher;
	};
	
};

#endif

