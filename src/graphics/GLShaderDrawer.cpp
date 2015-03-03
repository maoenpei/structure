

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
	, ElementType(GL_TRIANGLES)
{
}

GLShaderDrawer::~GLShaderDrawer()
{
	StateCacher->deleteBuffer(VertexBufferId);
	StateCacher->deleteIndexs(IndexsBufferId);
}

typedef void (*doUniformFunc)(GLuint l, CShaderDrawer::UniformValue *v);
static void doUniform1i(GLuint l, CShaderDrawer::UniformValue *v){glUniform1iv(l, v->n, (GLint *)v->ptr);}
static void doUniform1f(GLuint l, CShaderDrawer::UniformValue *v){glUniform1fv(l, v->n, (GLfloat *)v->ptr);}
static void doUniform2f(GLuint l, CShaderDrawer::UniformValue *v){glUniform2fv(l, v->n, (GLfloat *)v->ptr);}
static void doUniform4f(GLuint l, CShaderDrawer::UniformValue *v){glUniform4fv(l, v->n, (GLfloat *)v->ptr);}
static void doUniformMatrix4f(GLuint l, CShaderDrawer::UniformValue *v){glUniformMatrix4fv(l, v->n, GL_FALSE, (GLfloat *)v->ptr);}

void GLShaderDrawer::setUniformValue(unsigned int l,void * ptr,unsigned int n,const char * sig)
{
	CShaderDrawer::setUniformValue(l, ptr, n, sig);
	UniformValue *v = Uniforms[l];
	switch(sigTypes[sig]){
	case sig_int:
		v->ad[0] = (intptr_t)doUniform1i;
		break;
	case sig_float:
		v->ad[0] = (intptr_t)doUniform1f;
		break;
	case sig_vec2:
		v->ad[0] = (intptr_t)doUniform2f;
		break;
	case sig_vec4:
		v->ad[0] = (intptr_t)doUniform4f;
		break;
	case sig_mat4:
		v->ad[0] = (intptr_t)doUniformMatrix4f;
		break;
	default:
		assert(0);
	}
}

void GLShaderDrawer::setAttributeValue(unsigned int l,unsigned int offset,int n,const char * sig)
{
	CShaderDrawer::setAttributeValue(l, offset, n, sig);
	AttributeValue *v = Attributes[l];
	switch(sigTypes[sig]){
	case sig_int:
		v->ad[0] = (intptr_t)GL_INT;
		break;
	case sig_float:
		v->ad[0] = (intptr_t)GL_FLOAT;
		break;
	default:
		assert(0);
	}
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
	switch(sigTypes[sig]){
	case sig_int:
		IndexType = GL_INT;
		break;
	case sig_uint:
		IndexType = GL_UNSIGNED_INT;
		break;
	case sig_short:
		IndexType = GL_SHORT;
		break;
	case sig_ushort:
		IndexType = GL_UNSIGNED_SHORT;
		break;
	default:
		assert(0);
	}
	glGenBuffers(1, &IndexsBufferId);
	StateCacher->bindIndexs(IndexsBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sigSizes[sig] * IndexTotal, indexs, GL_STATIC_DRAW);
}

void GLShaderDrawer::setDrawType(unsigned int drawType)
{
	switch(drawType){
	case Draw_Triangle:
		ElementType = GL_TRIANGLES;
		break;
	case Draw_Line:
		ElementType = GL_LINES;
		break;
	case Draw_Point:
		ElementType = GL_POINTS;
		break;
	}
}

void GLShaderDrawer::drawAll()
{
	assert(Total > 0 && IndexTotal > 0 && VertexBufferId && IndexsBufferId);

	GLShaderProgram *program = ShaderProgram->cast<GLShaderProgram>();

	// active program
	program->use();

	// active textures
	do {
		std::map<unsigned int, core::TAuto<ITexture> >::iterator it;
		GLTexture *glTex;
		for (it = Textures.begin(); it != Textures.end(); it++){
			StateCacher->setActiveTexture(it->first);
			glTex = it->second->cast<GLTexture>();
			glTex->bind();
		}
	} while(0);

	// active uniforms
	do {
		std::map<unsigned int, core::TAuto<UniformValue> >::iterator it;
		for (it = Uniforms.begin(); it != Uniforms.end(); it++){
			UniformValue *dat = it->second;
			if (program->updateUniformValue(it->first, dat->ptr, dat->n * sigSizes[dat->sig])){
				((doUniformFunc)dat->ad[0])(it->first, dat);
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
			attribIds[c++] = it->first;
			glVertexAttribPointer(it->first, dat->n, (GLenum)dat->ad[0], GL_FALSE, Stride, (GLvoid *)dat->offset);
		}
		StateCacher->setAttribStates(attribIds, c);
		delete [] attribIds;

		glDrawElements(ElementType, IndexTotal, IndexType, (GLvoid *)0);
	} while(0);
	
}

};


