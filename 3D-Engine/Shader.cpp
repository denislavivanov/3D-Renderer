#include <iostream>
#include <fstream>
#include "Shader.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::string VertexSource = Load(vertexPath);
    std::string FragmentSource = Load(fragmentPath);

    GLuint VertexID = Compile(GL_VERTEX_SHADER, VertexSource);
    GLuint FragmentID = Compile(GL_FRAGMENT_SHADER, FragmentSource);

    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, VertexID);
    glAttachShader(m_ProgramID, FragmentID);
    glLinkProgram(m_ProgramID);

    LinkError();
}

std::string Shader::Load(const char* path)
{
    std::ifstream file;
    std::string source, line;

    file.open(path, std::ios::in);

    if (!file.is_open())
    {
        std::cerr << std::string(path) + std::string(" failed to open") << std::endl;
        exit(-1);
    }

    while (std::getline(file, line))
    {
        source += line;
        source += '\n';
    }

    file.close();

    return source;
}

void Shader::CompileError(GLuint ShaderID)
{
    int return_code;
    glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &return_code);

    if (return_code == GL_FALSE)
    {
        int length;

        glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &length);

        char* errlog = new char[length];
        
        glGetShaderInfoLog(ShaderID, length, nullptr, errlog);
        
        std::cerr << errlog << std::endl;
        
        delete[] errlog;

        exit(-1);
    }
}

void Shader::LinkError()
{
    int return_code;
    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &return_code);

    if (return_code == GL_FALSE)
    {
        int length;

        glGetProgramiv(m_ProgramID, GL_INFO_LOG_LENGTH, &length);

        char* errlog = new char[length];

        glGetProgramInfoLog(m_ProgramID, length, nullptr, errlog);

        std::cerr << errlog << std::endl;

        delete[] errlog;

        exit(-1);
    }
}

GLuint Shader::Compile(GLuint type, const std::string& source)
{
    GLuint m_ShaderID = glCreateShader(type);

    const GLchar* p = source.c_str();

    glShaderSource(m_ShaderID, 1, &p, NULL);

    glCompileShader(m_ShaderID);

    CompileError(m_ShaderID);

    return m_ShaderID;
}

Shader::~Shader()
{
    glDeleteProgram(m_ProgramID);
}

void Shader::Bind() const
{
    glUseProgram(m_ProgramID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

GLuint Shader::GetID()
{
    return m_ProgramID;
}