#ifndef __BASE_I_SHADER_DRAWER_H__
#define __BASE_I_SHADER_DRAWER_H__

#include "core/IRef.h"
#include "IShaderProgram.h"
#include "ITexture.h"

namespace graphics{

	class IShaderDrawer : public virtual core::IRef
	{
	public:
		virtual IShaderProgram *getProgram() = 0;

		virtual void setTexture(int index, ITexture *tex) = 0;
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setAttributeValue(unsigned int l, unsigned int offset, const char *sig) = 0;
		virtual void setAttributeData(void *ptr, unsigned int n, unsigned int stride) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, unsigned int n, const char *sig) = 0;
	};
	
};

#endif

