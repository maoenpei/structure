

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
	FrameBuffer = new GLFramebuffer(StateCacher);
}

void GLGraphics::initAPIs()
{
	assert(glewInit() == GLEW_OK);
	assert(GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader);
	assert(glewIsSupported("GL_VERSION_2_0"));
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

ITransformer *GLGraphics::getTransformer()
{
	return Transformer;
}

void GLGraphics::createTexture(core::TAuto<ITexture> &texture, model::Sizei &siz)
{
	texture = new GLTexture(StateCacher, siz);
}

void GLGraphics::createTexture(core::TAuto<ITexture> &texture, model::IImage *image)
{
	texture = new GLTexture(StateCacher, image);
}

void GLGraphics::createProgram(core::TAuto<IShaderProgram> &program, const char *vertex, const char *frag)
{
	program = new GLShaderProgram(StateCacher, vertex, frag);
}

void GLGraphics::createBuffer(core::TAuto<IFramebuffer> &fb, const model::Sizei &siz)
{
	fb = new GLFramebuffer(StateCacher, siz);
}

IFramebuffer *GLGraphics::getBuffer()
{
	return FrameBuffer;
}

void GLGraphics::pushBuffer(IFramebuffer * buffer)
{
	CachedFramebuffers.push(FrameBuffer);
	FrameBuffer = buffer->cast<GLFramebuffer>();
}

void GLGraphics::popBuffer()
{
	if (CachedFramebuffers.size() > 0){
		FrameBuffer = CachedFramebuffers.top();
		CachedFramebuffers.pop();
	}
}

void GLGraphics::clear()
{
	FrameBuffer->clear();
}

void GLGraphics::pipeline(IShaderDrawer * drawer)
{
	GLShaderDrawer *glDrawer = drawer->cast<GLShaderDrawer>();
	GLShaderProgram *glProgram = glDrawer->getProgram()->cast<GLShaderProgram>();

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


