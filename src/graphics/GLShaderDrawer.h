#ifndef __GL_SHADER_DRAWER_H__
#define __GL_SHADER_DRAWER_H__

#include "IShaderDrawer.h"
#include "core/CRefObject.h"
#include "IShaderProgram.h"
#include "core/TAuto.h"
#include "GLStateCacher.h"
#include "ITransformer.h"
#include <map>
#include <string>

namespace graphics{

	struct UniformValue : public core::CRefObject{
		void *ptr;
		unsigned int n;
		std::string sig;
	};

	struct AttributeValue : public core::CRefObject{
		unsigned int offset;
		std::string sig;
	};
	
	class GLShaderDrawer : public core::CRefObject, public virtual IShaderDrawer
	{
	public:
		virtual IShaderProgram *getProgram();

		virtual void setTexture(int index, ITexture *tex);
		// sig: 1fv, 1iv, 3fv ...
		virtual void setUniformValue(unsigned int l, void *ptr, unsigned int n, const char *sig);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setAttributeValue(unsigned int l, unsigned int offset, const char *sig);
		virtual void setAttributeData(void *ptr, unsigned int n, unsigned int stride);
		// sig: GL_UNSIGNED_SHORT, GL_UNSIGNED_BYTE ...
		virtual void setIndexs(void *indexs, unsigned int n, const char *sig);

		GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program);
		virtual ~GLShaderDrawer();

		void drawAll(ITransformer *trans);

	private:
		core::TAuto<GLStateCacher> StateCacher;
		core::TAuto<IShaderProgram> ShaderProgram;
		
		std::map<unsigned int, core::TAuto<ITexture> > Textures;
		std::map<unsigned int, core::TAuto<UniformValue> > Uniforms;
		std::map<unsigned int, core::TAuto<AttributeValue> > Attributes;
	};
	
};

#endif

