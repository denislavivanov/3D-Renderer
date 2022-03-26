#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	std::string Load(const char* path);

	GLuint GetID();
	GLuint Compile(GLuint type, const std::string& source);

	void LinkError();
	void CompileError(GLuint ShaderID);

	void Bind() const;
	void Unbind() const;

private:
	GLuint m_ProgramID;
};

