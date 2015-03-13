

#include "GLTexture.h"
#include <assert.h>

namespace graphics{

static void getGLTextureFormat(model::IImage *image, GLint &format, GLint &interFormat, GLint &type)
{
	int channel = image->getChannel();
	assert(channel == 3 || channel == 4);
	if (channel == 3){
		interFormat = format = GL_RGB;
	}else if (channel == 4){
		interFormat = format = GL_RGBA;
	}
	type = GL_UNSIGNED_BYTE;
}

static void setGLTextureState()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

GLTexture::GLTexture(GLStateCacher *_statecacher, model::IImage *image)
	: StateCacher(_statecacher)
	, Size(image->getSize())
{
	glGenTextures(1, &TextureId);
	StateCacher->bindTexture(TextureId);
	setGLTextureState();
	
	GLint format;
	GLint interFormat;
	GLint type;
	getGLTextureFormat(image, format, interFormat, type);
	glTexImage2D(GL_TEXTURE_2D, 0, interFormat, (GLsizei)Size.w, (GLsizei)Size.h, 0, format, type, (GLvoid *)image->getData());
}

GLTexture::GLTexture(GLStateCacher *_statecacher, const model::Sizei &siz)
	: StateCacher(_statecacher)
	, Size(siz)
{
	glGenTextures(1, &TextureId);
	StateCacher->bindTexture(TextureId);
	setGLTextureState();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)Size.w, (GLsizei)Size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
}

GLTexture::~GLTexture()
{
	StateCacher->deleteTexture(TextureId);
}

const model::Sizei &GLTexture::getSize()
{
	return Size;
}

void GLTexture::bind()
{
	StateCacher->bindTexture(TextureId);
}

};


