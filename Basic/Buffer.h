#pragma once

#include <GL/glew.h>
#include <iostream>
#include "Renderer.h"

class Buffer
{
protected:
	GLuint m_RenderID;
	GLuint m_Type;
	GLuint m_DrawType;
public:
	Buffer() = default;
	Buffer(GLuint id, GLuint type, GLuint drawType);
	~Buffer();
	void Bind() const;
	void Unbind() const;
};

