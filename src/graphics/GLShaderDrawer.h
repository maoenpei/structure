#ifndef __GL_SHADER_DRAWER_H__
#define __GL_SHADER_DRAWER_H__

#include "IShaderDrawer.h"
#include "core/CRefObject.h"
#include "IShaderProgram.h"
#include "core/TAuto.h"
#include "GLStateCacher.h"

namespace graphics{

	class GLShaderDrawer : public core::CRefObject, public virtual IShaderDrawer
	{
	public:
		virtual IShaderProgram *getProgram();

		virtual void setTexture(int index, ITexture *tex);
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setAttributeValue(unsigned int l, void *ptr, unsigned int n, unsigned int stride, const char *sig);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, const char *sig);

		GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program);

	private:
		core::TAuto<GLStateCacher> StateCacher;
		core::TAuto<IShaderProgram> ShaderProgram;
	};
	
};

#endif

