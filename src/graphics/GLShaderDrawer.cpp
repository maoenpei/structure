

#include "GLShaderDrawer.h"

namespace graphics{

GLShaderDrawer::GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program)
	: StateCacher(_statecacher)
	, ShaderProgram(program)
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

void GLShaderDrawer::setAttributeValue(unsigned int l,void * ptr,unsigned int n,unsigned int stride,const char * sig)
{
}

void GLShaderDrawer::setIndexs(void * indexs,const char * sig)
{
}

};


