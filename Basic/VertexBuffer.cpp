#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLuint id, std::vector<GLfloat> verticies, GLuint drawType)
	: Buffer(id, GL_ARRAY_BUFFER, drawType), m_Verticies(verticies)
{
	Bind();
	GLCall(glBufferData(m_Type, m_Verticies.size() * sizeof(GLfloat), &verticies[0], m_DrawType));
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
}

VertexBuffer::~VertexBuffer()
{
}
