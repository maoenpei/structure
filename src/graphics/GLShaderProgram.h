#ifndef __GL_SHADER_PROGRAM_H__
#define __GL_SHADER_PROGRAM_H__

#include "IShaderProgram.h"
#include "GLStateCacher.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <string>
#include <map>

namespace graphics{

	class GLShaderProgram : public core::CRefObject, public virtual IShaderProgram
	{
	public:
		virtual void setTransformName(const char *name);
		virtual unsigned int getUniformIndex(const char *name);
		virtual unsigned int getAttributeIndex(const char *name);
		virtual void createDrawer(core::TAuto<IShaderDrawer> &drawer);

		GLShaderProgram(GLStateCacher *_statecacher, const char *vertex, const char *frag);
		virtual ~GLShaderProgram();

		unsigned int getTransformIndex();
		void use();
		
	private:
		static GLuint compileShader(const char *source, GLenum type);
		GLuint ProgramId;
		core::TAuto<GLStateCacher> StateCacher;
		std::string TransformName;

		typedef std::map<std::string, unsigned int> IndexMapType;
		IndexMapType UniformIndexs;
		IndexMapType AttributeIndexs;
	};
	
};

#endif


