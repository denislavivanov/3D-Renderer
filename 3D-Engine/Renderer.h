#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"


class Renderer
{
public:
	Renderer();

	~Renderer();

	void Run();

private:
	void Init();

private:
	Shader* shader;
	VertexArray* VAO;
	VertexBuffer* VBO;
	IndexBuffer* EBO;
	Texture* tex;
	Window m_Window;
};

