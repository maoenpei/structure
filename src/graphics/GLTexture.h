#ifndef __GL_TEXTURE_H__
#define __GL_TEXTURE_H__

#include "ITexture.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include "GLStateCacher.h"
#include "model/IImage.h"
#include "model/TGeometry.h"

namespace graphics{

	class GLTexture : public core::CRefObject, public virtual ITexture
	{
	public:
		GLTexture(GLStateCacher *_statecacher, model::IImage *image);
		GLTexture(GLStateCacher *_statecacher, const model::Sizei &siz);
		virtual ~GLTexture();
		
		virtual const model::Sizei &getSize();
		void bind();
	
	private:
		GLuint TextureId;
		model::Sizei Size;
		core::TAuto<GLStateCacher> StateCacher;
//		friend class GLFramebuffer;
	};
	
};

#endif


