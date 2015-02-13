#ifndef __GL_STATE_CACHER_H__
#define __GL_STATE_CACHER_H__

#include "core/CRefObject.h"
#include <glew.h>

namespace graphics{

	class GLStateCacher : public core::CRefObject
	{
	public:
		GLStateCacher();
		
		void bindTexture(GLuint uTex);
		void deleteTexture(GLuint uTex);
		void useProgram(GLuint uProg);
		void deleteProgram(GLuint uProg);
		void bindBuffer(GLuint uBuf);
		void deleteBuffer(GLuint uBuf);
		void bindIndexs(GLuint uIndexs);
		void deleteIndexs(GLuint uIndexs);

	private:
		GLuint BindTexture;
		GLuint UsingProgram;
		GLuint BindBuffer;
		GLuint BindIndexs;
	};
	
};

#endif

