#include "Buffer.h"

Buffer::Buffer(GLuint id, GLuint type, GLuint drawType)
	: m_RenderID(id), m_Type(type), m_DrawType(drawType)
{
	GLCall(glGenBuffers(1, &m_RenderID));
}

Buffer::~Buffer()
{}

void Buffer::Bind() const
{
	LOG(m_RenderID);
	LOG(m_Type);
	LOG(m_DrawType);
	GLCall(glBindBuffer(m_Type, m_RenderID));
}

void Buffer::Unbind() const
{
	GLCall(glBindBuffer(m_Type, 0));
}