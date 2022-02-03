#include "Renderer.h"

#include <iostream>


Renderer::Renderer()
	: m_Window(1280, 1024),
	  m_Shader("Shaders/vertex.shader", "Shaders/fragment.shader"),
	  m_Model("assets/head/")
{
	Init();
}

Renderer::~Renderer()
{
}

void Renderer::Run()
{
	while (!glfwWindowShouldClose(m_Window.GetWindow()))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_Model.Draw(m_Shader);

		m_Window.OnUpdate();
	}
}

void Renderer::Init()
{
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/

	/*float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.5f, 1.0f
	};*/

	/*float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
		 0.0f, 0.0f,
		 1.0f, 0.0f,
		 1.0f, 1.0f,
		 0.0f, 1.0f,
		 0.5f, 1.0f
	};

	unsigned int indices[] = {
		1, 0, 2,
		0, 2, 3
	};

	m_Mesh.vertices = new float[25];
	m_Mesh.indices = new unsigned int[6];

	memcpy(m_Mesh.vertices, vertices, 25 * sizeof(float));
	memcpy(m_Mesh.indices, indices, 6 * sizeof(unsigned int));

	m_Mesh.SetIndexCount(6);
	m_Mesh.SetDataCount(25);
	m_Mesh.SetTextureOffset(15 * sizeof(float));

	m_Mesh.LoadTexture("assets/head/textures/material_0_baseColor.png");
	m_Mesh.Load();*/

	/*VAO = new VertexArray();
	VBO = new VertexBuffer(vertices, sizeof(vertices));
	EBO = new IndexBuffer(indices, sizeof(indices));
	tex = new Texture("assets/textures/Checkerboard.png");
	
	tex->Bind();

	VAO->SetVertexBuffer(VBO);
	VAO->SetIndexBuffer(EBO);

	VBO->SetLayout(0, 3, 20, 0);
	VBO->SetLayout(1, 2, 20, 12);*/
}
