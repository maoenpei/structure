

#include "GLShaderDrawer.h"

namespace graphics{

enum{
	sig_int,
	sig_float,
	sig_vec2,
	sig_mat4,
	sig_max,
};

static std::map<std::string, int> sigSizes;
static std::map<std::string, unsigned int> sigTypes;

struct GLShaderDrawer::UniformValue : public core::CRefObject{
	unsigned char *ptr;
	unsigned int n;
	std::string sig;

	UniformValue(void *_ptr, unsigned int _n, const char *_sig)
		: n(_n), sig(_sig)
	{
		int size = n * sigSizes[sig];
		ptr = new unsigned char [size];
		memcpy(ptr, _ptr, size);
	}
	~UniformValue()
	{
		delete [] ptr;
	}
};

struct GLShaderDrawer::AttributeValue : public core::CRefObject{
	unsigned int offset;
	std::string sig;
};

GLShaderDrawer::GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program)
	: StateCacher(_statecacher)
	, ShaderProgram(program)
	, VertexBufferId(0)
	, IndexsBufferId(0)
{
}

GLShaderDrawer::~GLShaderDrawer()
{
	StateCacher->deleteBuffer(VertexBufferId);
	StateCacher->deleteIndexs(IndexsBufferId);
}

IShaderProgram *GLShaderDrawer::getProgram()
{
	return ShaderProgram;
}

void GLShaderDrawer::setTexture(int index, ITexture *tex)
{
	Textures[index] = tex;
}

void GLShaderDrawer::setUniformValue(unsigned int l,void * ptr,unsigned int n,const char * sig)
{
	Uniforms[l] = new UniformValue(ptr, n, sig);
}

void GLShaderDrawer::setAttributeValue(unsigned int l, unsigned int offset, const char *sig)
{
}

void GLShaderDrawer::setAttributeData(void * ptr,unsigned int n,unsigned int stride)
{
}

void GLShaderDrawer::setIndexs(void * indexs, unsigned int n,const char * sig)
{
}

void GLShaderDrawer::drawAll(ITransformer *trans)
{
}

};


