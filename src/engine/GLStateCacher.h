#ifndef __GL_STATE_CACHER_H__
#define __GL_STATE_CACHER_H__

#include "core/CRefObject.h"
#include <glew.h>

namespace engine{

	class GLStateCacher : public core::CRefObject
	{
	public:
		GLStateCacher();
		
		GLuint BindTexture;
		void bindTexture(GLuint uTex);
	};
	
};

#endif

