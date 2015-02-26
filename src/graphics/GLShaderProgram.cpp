

#include "GLShaderProgram.h"
#include "GLShaderDrawer.h"
#include <assert.h>

namespace graphics{

struct GLShaderProgram::UniformData : public core::CRefObject
{
	unsigned char *ptr;
	unsigned int siz;
	UniformData(void *_ptr, unsigned int _siz)
		: siz(_siz)
	{
		ptr = new unsigned char[siz];
		memcpy(ptr, _ptr, siz);
	}
	~UniformData()
	{
		delete [] ptr;
	}
};

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

bool GLShaderProgram::updateUniformValue(unsigned int l,void * ptr,unsigned int siz)
{
	std::map<unsigned int, core::TAuto<UniformData> >::iterator it;
	it = Uniforms.find(l);
	if (it != Uniforms.end()){
		UniformData *dat = it->second;
		if (dat->siz == siz && 0 == memcmp(dat->ptr, ptr, siz)){
			return false;
		}
	}
	Uniforms[l] = new UniformData(ptr, siz);
	return true;
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


