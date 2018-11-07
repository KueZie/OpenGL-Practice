#pragma once

#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include "Renderer.h"

struct ShaderProgramSource
{
	std::string VertexSource, FragmentSource;
};

class Shader
{
private:
	GLuint m_RenderID;
	std::map<std::string, int> m_LocationKeys;
	GLuint CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(const std::string& filepath);
	int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
	Shader(const std::string source);
	Shader() = default;
	Shader& operator=(const Shader&) = delete;
	Shader(const Shader&) = delete;
	~Shader();
	GLuint GetID() const;
	void SetUniform(const std::string& name, float x, float y, float z, float w);
};

