#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(GLuint id, std::vector<GLuint> indices, GLuint drawType)
	: Buffer(id, GL_ELEMENT_ARRAY_BUFFER, drawType), m_Indices(indices)
{
	Bind();
	GLCall(glBufferData(m_Type, m_Indices.size() * sizeof(GLuint), &indices[0], m_DrawType));
}

IndexBuffer::~IndexBuffer()
{}
