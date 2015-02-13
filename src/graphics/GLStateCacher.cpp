

#include "GLStateCacher.h"

namespace graphics{

GLStateCacher::GLStateCacher()
	: BindTexture(0)
	, UsingProgram(0)
	, BindBuffer(0)
	, BindIndexs(0)
{
}

void GLStateCacher::bindTexture(GLuint uTex)
{
	if (uTex != BindTexture){
		glBindTexture(GL_TEXTURE_2D, uTex);
		BindTexture = uTex;
	}
}

void GLStateCacher::deleteTexture(GLuint uTex)
{
	if (uTex){
		if (uTex == BindTexture){
			BindTexture = 0;
		}
		glDeleteTextures(1, &uTex);
	}
}

void GLStateCacher::useProgram(GLuint uProg)
{
	if (uProg != UsingProgram){
		glUseProgram(uProg);
		UsingProgram = uProg;
	}
}

void GLStateCacher::deleteProgram(GLuint uProg)
{
	if (uProg){
		if (uProg == UsingProgram){
			UsingProgram = 0;
		}
		glDeleteProgram(uProg);
	}
}

void GLStateCacher::bindBuffer(GLuint uBuf)
{
	if (uBuf != BindBuffer){
		glBindBuffer(GL_ARRAY_BUFFER, uBuf);
		BindBuffer = uBuf;
	}
}

void GLStateCacher::deleteBuffer(GLuint uBuf)
{
	if (uBuf){
		if (uBuf == BindBuffer){
			BindBuffer = 0;
		}
		glDeleteBuffers(1, &uBuf);
	}
}

void GLStateCacher::bindIndexs(GLuint uIndexs)
{
	if (uIndexs != BindIndexs){
		glBindBuffer(GL_ARRAY_BUFFER, uIndexs);
		BindIndexs = uIndexs;
	}
}

void GLStateCacher::deleteIndexs(GLuint uIndexs)
{
	if (uIndexs){
		if (uIndexs == BindIndexs){
			BindIndexs = 0;
		}
		glDeleteBuffers(1, &uIndexs);
	}
}

};


