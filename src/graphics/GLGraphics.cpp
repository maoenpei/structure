

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

void GLGraphics::pipeline(IShaderDrawer * drawer)
{
	GLShaderDrawer *glDrawer = dynamic_cast<GLShaderDrawer *>(drawer);
	GLShaderProgram *glProgram = dynamic_cast<GLShaderProgram *>(glDrawer->getProgram());

	// update transform matrix
	unsigned int l = glProgram->getTransformIndex();
	unsigned int mode;
	void *ptr = Transformer->getMode(mode);
	switch(mode){
	case TransformMode_2D:
		glDrawer->setUniformValue(l, ptr, 3, SIG_VEC2);
		break;
	case TransformMode_3D:
		glDrawer->setUniformValue(l, ptr, 1, SIG_MAT4);
		break;
	}

	// do draw
	glDrawer->drawAll();
	
}

};


