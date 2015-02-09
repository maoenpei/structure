#ifndef __BASE_I_SHADER_DRAWER_H__
#define __BASE_I_SHADER_DRAWER_H__

#include "core/IRef.h"
#include "IShaderProgram.h"
#include "ITexture.h"

namespace engine{

	class IShaderDrawer : public virtual core::IRef
	{
	public:
		virtual IShaderProgram *getProgram() = 0;

		virtual void setTexture(int index, ITexture *tex) = 0;
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setVertexArrayValue(unsigned int l, void *ptr, unsigned int n, unsigned int stride, const char *sig) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, const char *sig) = 0;
	};
	
};

#endif

