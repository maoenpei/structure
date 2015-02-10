

#include "GLGraphics.h"
#include "CTransformer.h"
#include <assert.h>

namespace engine{

GLGraphics::GLGraphics()
{
	Transformer = new CTransformer();
}

void GLGraphics::initAPIs()
{
	assert(glewInit() == GLEW_OK);
	assert(GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader);
	assert(glewIsSupported("GL_VERSION_2_0"));
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


