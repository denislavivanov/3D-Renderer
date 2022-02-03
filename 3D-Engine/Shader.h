#pragma once
#include <GL/glew.h>
#include <string>

class Shader
{
public:
	std::string Load(const char* path);

	GLuint Compile(GLuint type, const std::string& source);

	void CompileError(GLuint ShaderID);

	void LinkError();

	GLuint GetID();

	void Bind() const;

	void Unbind() const;

	Shader(const char* vertexPath, const char* fragmentPath);

	~Shader();

private:
	GLuint m_ProgramID;
};

