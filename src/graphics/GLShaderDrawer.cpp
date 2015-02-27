

#include "GLShaderDrawer.h"
#include "GLShaderProgram.h"
#include "GLTexture.h"
#include <assert.h>

namespace graphics{

GLShaderDrawer::GLShaderDrawer(GLStateCacher *_statecacher, IShaderProgram *program)
	: CShaderDrawer(program)
	, StateCacher(_statecacher)
	, VertexBufferId(0)
	, IndexsBufferId(0)
	, Stride(0)
	, Total(0)
{
}

GLShaderDrawer::~GLShaderDrawer()
{
	StateCacher->deleteBuffer(VertexBufferId);
	StateCacher->deleteIndexs(IndexsBufferId);
}

void GLShaderDrawer::setAttributeData(void * ptr, unsigned int total, unsigned int stride)
{
	if (VertexBufferId){
		StateCacher->deleteBuffer(VertexBufferId);
	}
	Stride = stride;
	Total = total;
	glGenBuffers(1, &VertexBufferId);
	StateCacher->bindBuffer(VertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, Stride * Total, ptr, GL_DYNAMIC_DRAW);
}

void GLShaderDrawer::updateAttributeData(void * ptr, unsigned int start, unsigned int n)
{
	if (VertexBufferId){
		StateCacher->bindBuffer(VertexBufferId);
		glBufferSubData(GL_ARRAY_BUFFER, Stride * start, Stride * n , ptr);
	}
}

void GLShaderDrawer::setIndexs(void * indexs, unsigned int total, const char * sig)
{
	if (IndexsBufferId){
		StateCacher->deleteIndexs(IndexsBufferId);
	}
	IndexTotal = total;
	IndexSig = sig;
	glGenBuffers(1, &IndexsBufferId);
	StateCacher->bindIndexs(IndexsBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sigSizes[sig] * IndexTotal, indexs, GL_STATIC_DRAW);
}

void GLShaderDrawer::drawAll()
{
	assert(Total > 0 && IndexTotal > 0 && VertexBufferId && IndexsBufferId);

	GLShaderProgram *program = ShaderProgram.cast<GLShaderProgram>();

	// active program
	program->use();

	// active textures
	do {
		std::map<unsigned int, core::TAuto<ITexture> >::iterator it;
		GLTexture *glTex;
		for (it = Textures.begin(); it != Textures.end(); it++){
			StateCacher->setActiveTexture(it->first);
			glTex = it->second.cast<GLTexture>();
			glTex->bind();
		}
	} while(0);

	// active uniforms
	do {
		std::map<unsigned int, core::TAuto<UniformValue> >::iterator it;
		for (it = Uniforms.begin(); it != Uniforms.end(); it++){
			UniformValue *dat = it->second;
			if (program->updateUniformValue(it->first, dat->ptr, dat->n * sigSizes[dat->sig])){
				switch(sigTypes[dat->sig]){
				case sig_int:
					glUniform1iv(it->first, dat->n, (GLint *)dat->ptr);
					break;
				case sig_float:
					glUniform1fv(it->first, dat->n, (GLfloat *)dat->ptr);
					break;
				case sig_vec2:
					glUniform2fv(it->first, dat->n, (GLfloat *)dat->ptr);
					break;
				case sig_mat4:
					glUniformMatrix4fv(it->first, dat->n, GL_FALSE, (GLfloat *)dat->ptr);
					break;
				default:
					assert(0);
				}
			}
		}
	} while(0);

	// active attributes
	do {
		StateCacher->bindBuffer(VertexBufferId);
		StateCacher->bindIndexs(IndexsBufferId);

		int c = (int)Attributes.size();
		int *attribIds = new int[c];
		c = 0;
		std::map<unsigned int, core::TAuto<AttributeValue> >::iterator it;
		for (it = Attributes.begin(); it != Attributes.end(); it++){
			AttributeValue *dat = it->second;
			GLenum type;
			switch(sigTypes[dat->sig]){
			case sig_int:
				type = GL_INT;
				break;
			case sig_float:
				type = GL_FLOAT;
				break;
			}
			attribIds[c++] = it->first;
			glVertexAttribPointer(it->first, dat->n, type, GL_FALSE, Stride, (GLvoid *)dat->offset);
		}
		StateCacher->setAttribStates(attribIds, c);
		delete [] attribIds;

		GLenum type;
		switch(sigTypes[IndexSig]){
		case sig_int:
			type = GL_INT;
			break;
		case sig_uint:
			type = GL_UNSIGNED_INT;
			break;
		case sig_short:
			type = GL_SHORT;
			break;
		case sig_ushort:
			type = GL_UNSIGNED_SHORT;
			break;
		}
		glDrawElements(GL_TRIANGLES, IndexTotal, type, (GLvoid *)0);
	} while(0);
	
}

};


