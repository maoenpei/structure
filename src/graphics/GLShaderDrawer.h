#ifndef __GL_SHADER_DRAWER_H__
#define __GL_SHADER_DRAWER_H__

#include "CShaderDrawer.h"
#include "GLStateCacher.h"
#include "ITransformer.h"
#include <string>

namespace graphics{

	class GLShaderDrawer : public CShaderDrawer
	{
	public:
		virtual void setAttributeData(void *ptr, unsigned int total, unsigned int stride);
		virtual void updateAttributeData(void * ptr, unsigned int start, unsigned int n);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, unsigned int total, const char *sig);

		GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program);
		virtual ~GLShaderDrawer();

		void drawAll();

	private:
		core::TAuto<GLStateCacher> StateCacher;

		GLuint VertexBufferId;
		GLuint IndexsBufferId;
		unsigned int Stride;
		unsigned int Total;
		unsigned int IndexTotal;
		std::string IndexSig;
	};
	
};

#endif

