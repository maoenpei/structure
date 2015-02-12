

#include "GLGraphics.h"
#include "CTransformer.h"
#include "ITexture.h"
#include "GLShaderProgram.h"
#include <assert.h>

namespace graphics{

class GLTexture : public core::CRefObject, public virtual ITexture
{
public:
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
	
	GLTexture(GLStateCacher *_statecacher, model::IImage *image)
		: StateCacher(_statecacher)
		, Size(image->getSize())
	{
		glGenTextures(1, &TextureId);
		StateCacher->bindTexture(TextureId);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		
		GLint format;
		GLint interFormat;
		GLint type;
		getGLTextureFormat(image, format, interFormat, type);
		glTexImage2D(GL_TEXTURE_2D, 0, interFormat, (GLsizei)Size.w, (GLsizei)Size.h, 0, format, type, (GLvoid *)image->getData());
	}
	virtual ~GLTexture()
	{
		if (StateCacher->BindTexture == TextureId){
			StateCacher->bindTexture(0);
		}
		glDeleteTextures(1, &TextureId);
	}
	virtual const model::Sizei &getSize()
	{
		return Size;
	}

private:
	GLuint TextureId;
	model::Sizei Size;
	core::TAuto<GLStateCacher> StateCacher;
};

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
}

};


