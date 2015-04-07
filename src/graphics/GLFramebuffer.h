#ifndef __GL_FRAME_BUFFER_H__
#define __GL_FRAME_BUFFER_H__

#include "IFramebuffer.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include "model/TGeometry.h"
#include "GLStateCacher.h"
#include "GLTexture.h"

namespace graphics{

	class GLFramebuffer : public core::CRefObject, public virtual IFramebuffer
	{
	public:
		virtual void setBackground(const model::Color4f &color);
		virtual void openDepth(float defDepth);
		
		virtual void copyImage(ITexture *tex);

		void clear();

		GLFramebuffer(GLStateCacher *_statecacher);
		GLFramebuffer(GLStateCacher *_statecacher, const model::Sizei &siz);
		~GLFramebuffer();

	private:
		core::TAuto<GLStateCacher> StateCacher;
		model::Sizei Size;
		model::Color4f Color;
		float DefaultDepth;

		// contained objects
		GLuint ColorBufferId;
		GLuint DepthBufferId;
		
		GLuint FramebufferId;
		GLbitfield ClearField;
	};
	
};

#endif

