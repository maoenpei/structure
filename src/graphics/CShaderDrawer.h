#ifndef __BASE_SHADER_DRAWER_H__
#define __BASE_SHADER_DRAWER_H__

#include "IShaderDrawer.h"
#include "core/CRefObject.h"
#include "IShaderProgram.h"
#include "core/TAuto.h"
#include <map>
#include <string>

namespace graphics{

	class CShaderDrawer : public core::CRefObject, public virtual IShaderDrawer
	{
	public:
		virtual IShaderProgram *getProgram();

		virtual void setTexture(int index, ITexture *tex);
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setAttributeValue(unsigned int l, unsigned int offset, int n, const char *sig);

		CShaderDrawer(IShaderProgram *program);
		virtual ~CShaderDrawer();

	protected:
		core::TAuto<IShaderProgram> ShaderProgram;

		struct UniformValue : public core::CRefObject
		{
			unsigned char *ptr;
			unsigned int n;
			std::string sig;
			UniformValue(void *_ptr, unsigned int _n, const char *_sig);
			~UniformValue();
		};
		struct AttributeValue : public core::CRefObject
		{
			unsigned int offset;
			int n;
			std::string sig;
			AttributeValue(unsigned int _offset, int _n, const char *_sig);
		};
		std::map<unsigned int, core::TAuto<ITexture> > Textures;
		std::map<unsigned int, core::TAuto<UniformValue> > Uniforms;
		std::map<unsigned int, core::TAuto<AttributeValue> > Attributes;
		
	};
	
};

enum{
	sig_int,
	sig_uint,
	sig_short,
	sig_ushort,
	sig_float,
	sig_vec2,
	sig_mat4,
	sig_max
};

#define SIG_INT			"int"
#define SIG_UINT		"uint"
#define SIG_SHORT		"short"
#define SIG_USHORT		"ushort"
#define SIG_FLOAT		"float"
#define SIG_VEC2		"vec2"
#define SIG_MAT4		"mat4"

extern std::map<std::string, int> sigSizes;
extern std::map<std::string, unsigned int> sigTypes;

#endif

