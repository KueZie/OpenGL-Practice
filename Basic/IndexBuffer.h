#pragma once

#include <GL/glew.h>
#include <vector>
#include "Renderer.h"
#include "Buffer.h"

class IndexBuffer : private Buffer
{
private:
	std::vector<GLuint> m_Indices;
public:
	IndexBuffer() = default;
	IndexBuffer(GLuint id, std::vector<GLuint> indices, GLuint drawType);
	~IndexBuffer();
};
