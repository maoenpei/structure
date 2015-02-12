

#include "GLStateCacher.h"

namespace engine{

GLStateCacher::GLStateCacher()
	: BindTexture(0)
{
}

void GLStateCacher::bindTexture(GLuint uTex)
{
	if (uTex != BindTexture){
		glBindTexture(GL_TEXTURE_2D, uTex);
		BindTexture = uTex;
	}
}

};


