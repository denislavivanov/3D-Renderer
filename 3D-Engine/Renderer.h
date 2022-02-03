#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"
#include "Buffers/VertexArray.h"
#include "Buffers/VertexBuffer.h"
#include "Buffers/IndexBuffer.h"
#include "Texture.h"
#include "Model.h"


class Renderer
{
public:
	Renderer();

	~Renderer();

	void Run();

private:
	void Init();

private:
	Window m_Window;
	Shader m_Shader;
	Model m_Model;
	//Mesh m_Mesh;
};

