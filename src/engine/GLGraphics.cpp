

#include "GLGraphics.h"
#include "CTransformer.h"

namespace engine{

GLGraphics::GLGraphics()
{
	Transformer = new CTransformer();
}

ITransformer *GLGraphics::getTransformer()
{
	return Transformer;
}

ITexture *GLGraphics::loadTexture(model::IImage *image)
{
	return 0;
}

IShaderProgram *GLGraphics::loadProgram(const char * vertex,const char * frag)
{
	return 0;
}

void GLGraphics::pipeline(IShaderDrawer * drawer,int n)
{
}

};


