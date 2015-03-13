

#include "GLStateCacher.h"
#include <string>
#include <assert.h>

namespace graphics{

GLStateCacher::GLStateCacher()
	: UsingProgram(0)
	, CurrentBuffer(0)
	, CurrentIndexs(0)
	, TextureIndex(0)
	, CurrentFramebuffer(0)
{
	memset(BindTextures, 0, sizeof(BindTextures));
}

void GLStateCacher::bindTexture(GLuint uTex)
{
	if (uTex != BindTextures[TextureIndex]){
		glBindTexture(GL_TEXTURE_2D, uTex);
		BindTextures[TextureIndex] = uTex;
	}
}

void GLStateCacher::deleteTexture(GLuint uTex)
{
	if (uTex){
		if (uTex == BindTextures[TextureIndex]){
			BindTextures[TextureIndex] = 0;
		}
		glDeleteTextures(1, &uTex);
	}
}

void GLStateCacher::setActiveTexture(int active)
{
	static GLenum glTextureIndexs[] = {
		GL_TEXTURE0,GL_TEXTURE1,GL_TEXTURE2,GL_TEXTURE3,
		GL_TEXTURE4,GL_TEXTURE5,GL_TEXTURE6,GL_TEXTURE7,
		GL_TEXTURE8,GL_TEXTURE9,GL_TEXTURE10,GL_TEXTURE11,
		GL_TEXTURE12,GL_TEXTURE13,GL_TEXTURE14,GL_TEXTURE15,
	};
	assert(active >= 0 && active < MAX_TEXTURES);
	if (active != TextureIndex){
		glActiveTexture(glTextureIndexs[active]);
		TextureIndex = active;
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
	if (uBuf != CurrentBuffer){
		glBindBuffer(GL_ARRAY_BUFFER, uBuf);
		CurrentBuffer = uBuf;
	}
}

void GLStateCacher::deleteBuffer(GLuint uBuf)
{
	if (uBuf){
		if (uBuf == CurrentBuffer){
			CurrentBuffer = 0;
		}
		glDeleteBuffers(1, &uBuf);
	}
}

void GLStateCacher::bindIndexs(GLuint uIndexs)
{
	if (uIndexs != CurrentIndexs){
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uIndexs);
		CurrentIndexs = uIndexs;
	}
}

void GLStateCacher::deleteIndexs(GLuint uIndexs)
{
	if (uIndexs){
		if (uIndexs == CurrentIndexs){
			CurrentIndexs = 0;
		}
		glDeleteBuffers(1, &uIndexs);
	}
}

void GLStateCacher::setAttribStates(GLint arr[], int n)
{
	std::set<GLint> values;
	for (int i = 0; i<n; i++){
		if (AttributeStates.find(arr[i]) == AttributeStates.end()){
			glEnableVertexAttribArray(arr[i]);
		}
		values.insert(arr[i]);
	}

	std::set<GLint>::iterator it;
	for (it = AttributeStates.begin(); it != AttributeStates.end(); it++){
		if (values.find(*it) == values.end()){
			glDisableVertexAttribArray(*it);
		}
	}
	AttributeStates.swap(values);
}

void GLStateCacher::bindFramebuffer(GLuint uFBO)
{
	if (uFBO != CurrentFramebuffer){
		glBindFramebuffer(GL_FRAMEBUFFER, uFBO);
		CurrentFramebuffer = uFBO;
	}
}

void GLStateCacher::deleteFramebuffer(GLuint uFBO)
{
	if (uFBO){
		if (CurrentFramebuffer == uFBO){
			CurrentFramebuffer = 0;
		}
		glDeleteFramebuffers(1, &uFBO);
	}
}

};


