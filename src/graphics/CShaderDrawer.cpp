

#include "CShaderDrawer.h"
#include "core/TConstructor.h"

namespace graphics{

CShaderDrawer::UniformValue::UniformValue(void *_ptr, unsigned int _n, const char *_sig)
	: n(_n), sig(_sig)
{
	int size = n * sigSizes[sig];
	ptr = new unsigned char [size];
	memcpy(ptr, _ptr, size);
}

CShaderDrawer::UniformValue::~UniformValue()
{
	delete [] ptr;
}

CShaderDrawer::AttributeValue::AttributeValue(unsigned int _offset, int _n, const char *_sig)
	: offset(_offset), n(_n), sig(_sig)
{
}

CShaderDrawer::CShaderDrawer(IShaderProgram *program)
	: ShaderProgram(program)
{
}

CShaderDrawer::~CShaderDrawer()
{}

IShaderProgram *CShaderDrawer::getProgram()
{
	return ShaderProgram;
}

void CShaderDrawer::setTexture(ITexture *tex, int index)
{
	Textures[index] = tex;
}

void CShaderDrawer::setUniformValue(unsigned int l,void * ptr,unsigned int n,const char * sig)
{
	Uniforms[l] = new UniformValue(ptr, n, sig);
}

void CShaderDrawer::setAttributeValue(unsigned int l, unsigned int offset, int n, const char *sig)
{
	Attributes[l] = new AttributeValue(offset, n, sig);
}

};

std::map<std::string, int> sigSizes;
std::map<std::string, unsigned int> sigTypes;

__construct_global(SHADER_DRAWER_SIGS,{
	sigSizes[SIG_INT] = sizeof(int);
	sigTypes[SIG_INT] = sig_int;
	sigSizes[SIG_UINT] = sizeof(unsigned int);
	sigTypes[SIG_UINT] = sig_uint;
	sigSizes[SIG_SHORT] = sizeof(short);
	sigTypes[SIG_SHORT] = sig_short;
	sigSizes[SIG_USHORT] = sizeof(unsigned short);
	sigTypes[SIG_USHORT] = sig_ushort;
	sigSizes[SIG_FLOAT] = sizeof(float);
	sigTypes[SIG_FLOAT] = sig_float;
	sigSizes[SIG_VEC2] = sizeof(float) * 2;
	sigTypes[SIG_VEC2] = sig_vec2;
	sigSizes[SIG_VEC4] = sizeof(float) * 4;
	sigTypes[SIG_VEC4] = sig_vec4;
	sigSizes[SIG_MAT4] = sizeof(float) * 4 * 4;
	sigTypes[SIG_MAT4] = sig_mat4;
});


