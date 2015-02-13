

#include "GLGraphics.h"
#include "CTransformer.h"
#include "GLTexture.h"
#include "GLShaderProgram.h"
#include "GLShaderDrawer.h"
#include <assert.h>

namespace graphics{

GLGraphics::GLGraphics()
{
	Transformer = new CTransformer();
	StateCacher = new GLStateCacher();
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

void GLGraphics::loadTexture(core::TAuto<ITexture> &texture, model::IImage *image)
{
	texture = new GLTexture(StateCacher, image);
}

void GLGraphics::loadProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag)
{
	program = new GLShaderProgram(StateCacher, vertex, frag);
}

void GLGraphics::cleanBuffer()
{
	
}

void GLGraphics::pipeline(IShaderDrawer * drawer, int n)
{
	GLShaderDrawer *glDrawer = dynamic_cast<GLShaderDrawer *>(drawer);
	glDrawer->drawAll(Transformer);
}

};


