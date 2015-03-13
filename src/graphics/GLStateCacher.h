#ifndef __GL_STATE_CACHER_H__
#define __GL_STATE_CACHER_H__

#include "core/CRefObject.h"
#include <glew.h>
#include <set>

#define MAX_TEXTURES		16

namespace graphics{

	class GLStateCacher : public core::CRefObject
	{
	public:
		GLStateCacher();
		
		void bindTexture(GLuint uTex);
		void deleteTexture(GLuint uTex);
		void setActiveTexture(int active);
		
		void useProgram(GLuint uProg);
		void deleteProgram(GLuint uProg);
		
		void bindBuffer(GLuint uBuf);
		void deleteBuffer(GLuint uBuf);
		void bindIndexs(GLuint uIndexs);
		void deleteIndexs(GLuint uIndexs);

		void setAttribStates(GLint arr[], int n);

		void bindFramebuffer(GLuint uFBO);
		void deleteFramebuffer(GLuint uFBO);

	private:
		GLuint BindTextures[MAX_TEXTURES];
		int TextureIndex;
		GLuint UsingProgram;
		GLuint CurrentBuffer;
		GLuint CurrentIndexs;
		std::set<GLint> AttributeStates;
		GLuint CurrentFramebuffer;
	};
	
};

#endif

