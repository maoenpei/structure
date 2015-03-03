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

		virtual void setTexture(ITexture *tex, int index) = 0;
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setAttributeValue(unsigned int l, unsigned int offset, int n, const char *sig) = 0;
		virtual void setAttributeData(void *ptr, unsigned int total, unsigned int stride) = 0;
		virtual void updateAttributeData(void * ptr, unsigned int start, unsigned int n) = 0;
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, unsigned int total, const char *sig) = 0;
	};
	
};

#define SIG_INT			"int"
#define SIG_UINT		"uint"
#define SIG_SHORT		"short"
#define SIG_USHORT		"ushort"
#define SIG_FLOAT		"float"
#define SIG_VEC2		"vec2"
#define SIG_VEC4		"vec4"
#define SIG_MAT4		"mat4"

#endif

