

#include "GLFramebuffer.h"

namespace graphics{

GLFramebuffer::GLFramebuffer(GLStateCacher *_statecacher)
	: StateCacher(_statecacher)
	, FramebufferId(0)
	, ClearField(GL_COLOR_BUFFER_BIT)
	, DefaultDepth(0)
	, DepthBufferId(0)
{
}

GLFramebuffer::GLFramebuffer(GLStateCacher *_statecacher, const model::Sizei &siz)
	: StateCacher(_statecacher)
	, ClearField(GL_COLOR_BUFFER_BIT)
{
	AttachTexture = new GLTexture(StateCacher, siz);
	
	glGenFramebuffers(1, &FramebufferId);
	StateCacher->bindFramebuffer(FramebufferId);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, AttachTexture->TextureId, 0);
}

GLFramebuffer::~GLFramebuffer()
{
	if (DepthBufferId){
		glDeleteRenderbuffers(1, &DepthBufferId);
	}
	StateCacher->deleteFramebuffer(FramebufferId);
}

void GLFramebuffer::setBackground(const model::Color4f &color)
{
	Color = color;
}

void GLFramebuffer::openDepth(float defDepth)
{
	if ((ClearField & GL_DEPTH_BUFFER_BIT) == 0){
		ClearField |= GL_DEPTH_BUFFER_BIT;
		DefaultDepth = defDepth;

		GLenum err = glGetError();
		StateCacher->bindFramebuffer(FramebufferId);
		err = glGetError();
		glGenRenderbuffers(1, &DepthBufferId);
		err = glGetError();
		glBindRenderbuffer(GL_RENDERBUFFER, DepthBufferId);
		err = glGetError();
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, (GLsizei)Size.w, (GLsizei)Size.h);
		err = glGetError();
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, DepthBufferId);
		err = glGetError();
	}
	GLenum ret = glCheckFramebufferStatus(GL_FRAMEBUFFER);
}

void GLFramebuffer::clear()
{
	StateCacher->bindFramebuffer(FramebufferId);
	glClearColor(Color.r, Color.g, Color.b, Color.a);
	if (ClearField & GL_DEPTH_BUFFER_BIT){
		glClearDepth(DefaultDepth);
	}
	glClear(ClearField);
}

void GLFramebuffer::copyImage(ITexture *tex)
{
	GLTexture *glTex = tex->cast<GLTexture>();
	const model::Sizei &siz = tex->getSize();
	StateCacher->bindFramebuffer(FramebufferId);
	glTex->bind();
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, (GLsizei)siz.w, (GLsizei)siz.h, 0);
}

};


