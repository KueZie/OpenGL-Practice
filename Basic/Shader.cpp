#include "Shader.h"



Shader::Shader(const std::string source)
{
	ShaderProgramSource parsed = this->ParseShader(source);
	this->m_RenderID = this->CreateShader(parsed.VertexSource, parsed.FragmentSource);
}

Shader::

Shader::~Shader()
{
}

GLuint Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE)
	{
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << message << std::endl;
		GLCall(glDeleteShader(id));
		return 0;
	}

	return id;
}

ShaderProgramSource Shader::ParseShader(const std::string& filepath)
{
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };
}

int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = this->CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = this->CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));
	return program;
}

GLuint Shader::GetID() const
{
	return this->m_RenderID;
}

void Shader::SetUniform(const std::string& name, float x, float y, float z, float w)
{
	int location;
	if (m_LocationKeys.find(name) == m_LocationKeys.end())
	{
		GLCall(location = glGetUniformLocation(this->GetID(), name.c_str()));
		m_LocationKeys.insert(std::pair<std::string, int>(name, location));
	}
	else
	{
		location = m_LocationKeys[name];
	}
	glUniform4f(location, x, y, z, w);
}