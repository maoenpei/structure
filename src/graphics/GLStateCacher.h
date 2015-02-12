#ifndef __GL_STATE_CACHER_H__
#define __GL_STATE_CACHER_H__

#include "core/CRefObject.h"
#include <glew.h>

namespace graphics{

	class GLStateCacher : public core::CRefObject
	{
	public:
		GLStateCacher();
		
		GLuint BindTexture;
		void bindTexture(GLuint uTex);

		GLuint UsingProgram;
		void useProgram(GLuint uProg);
	};
	
};

#endif

