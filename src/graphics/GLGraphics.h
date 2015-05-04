#ifndef __GL_GRAPHICS_H__
#define __GL_GRAPHICS_H__

#include "IGraphics.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <glew.h>
#include "GLStateCacher.h"
#include <stack>
#include "GLFramebuffer.h"

namespace graphics{

	class GLGraphics : public core::CRefObject, public virtual IGraphics
	{
	public:
		virtual ITransformer *getTransformer();
		
		virtual void createTexture(core::TAuto<ITexture> &texture, model::Sizei &siz);
		virtual void createTexture(core::TAuto<ITexture> &texture, model::IImage *image);
		virtual void createProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag);

		virtual void createBuffer(core::TAuto<IFramebuffer> &fb, const model::Sizei &siz);
		virtual IFramebuffer *getBuffer();
		virtual void pushBuffer(IFramebuffer *buffer);
		virtual void popBuffer();

		virtual void clear();
		virtual void pipeline(IShaderDrawer *drawer);

		void initAPIs();
		GLGraphics();

	private:
		core::TAuto<ITransformer> Transformer;
		core::TAuto<GLStateCacher> StateCacher;
		core::TAuto<GLFramebuffer> FrameBuffer;
		std::stack<core::TAuto<GLFramebuffer> > CachedFramebuffers;
	};
	
};

#endif

