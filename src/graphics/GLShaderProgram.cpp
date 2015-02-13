

#include "GLShaderProgram.h"
#include "GLShaderDrawer.h"
#include <assert.h>

namespace graphics{

static GLuint compileShader(const char * source,GLenum type)
{
	GLuint shaderId = glCreateShader(type);
	glShaderSource(shaderId, 1, &source, 0);
	glCompileShader(shaderId);
	return shaderId;
}

GLShaderProgram::GLShaderProgram(GLStateCacher *_statecacher, const char *vertex, const char *frag)
	: StateCacher(_statecacher)
{
	ProgramId = glCreateProgram();
	
	GLuint vertexId = compileShader(vertex, GL_VERTEX_SHADER);
	glAttachShader(ProgramId, vertexId);
	glDeleteShader(vertexId);
	
	GLuint fragId = compileShader(frag, GL_FRAGMENT_SHADER);
	glAttachShader(ProgramId, fragId);
	glDeleteShader(fragId);

	glLinkProgram(ProgramId);
}

GLShaderProgram::~GLShaderProgram()
{
	StateCacher->deleteProgram(ProgramId);
}

unsigned int GLShaderProgram::getTransformIndex()
{
	assert(TransformName != "");
	return getUniformIndex(TransformName.c_str());
}

void GLShaderProgram::use()
{
	StateCacher->useProgram(ProgramId);
}

void GLShaderProgram::setTransformName(const char * name)
{
	TransformName = name;
}

unsigned int GLShaderProgram::getUniformIndex(const char * name)
{
	std::string uniName(name);
	IndexMapType::iterator it = UniformIndexs.find(uniName);
	if (it != UniformIndexs.end()){
		return it->second;
	}
	GLuint uniId = glGetUniformLocation(ProgramId, name);
	UniformIndexs[uniName] = uniId;
	return uniId;
}

unsigned int GLShaderProgram::getAttributeIndex(const char * name)
{
	std::string attribName(name);
	IndexMapType::iterator it = AttributeIndexs.find(attribName);
	if (it != AttributeIndexs.end()){
		return it->second;
	}
	GLuint attribId = glGetAttribLocation(ProgramId, name);
	AttributeIndexs[attribName] = attribId;
	return attribId;
}

void GLShaderProgram::createDrawer(core::TAuto<IShaderDrawer> &drawer)
{
	drawer = new GLShaderDrawer(StateCacher, this);
}

};


