

#include "GLShaderDrawer.h"

namespace graphics{

GLShaderDrawer::GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program)
	: StateCacher(_statecacher)
	, ShaderProgram(program)
{
}

GLShaderDrawer::~GLShaderDrawer()
{
}

IShaderProgram *GLShaderDrawer::getProgram()
{
	return ShaderProgram;
}

void GLShaderDrawer::setTexture(int index, ITexture *tex)
{
}

void GLShaderDrawer::setUniformValue(unsigned int l,void * ptr,unsigned int n,const char * sig)
{
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


