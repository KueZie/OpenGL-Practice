#pragma once

#include <GL/glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#define LOG(x) { std::cout << x << std::endl; }

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);