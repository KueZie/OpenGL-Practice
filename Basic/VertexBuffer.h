#pragma once

#include <GL/glew.h>
#include <vector>
#include "Renderer.h"
#include "Buffer.h"

class VertexBuffer : private Buffer
{
private:
	std::vector<GLfloat> m_Verticies;
public:
	VertexBuffer() = default;
	VertexBuffer(GLuint id, std::vector<GLfloat> verticies, GLuint drawType);
	~VertexBuffer();
};

