#include "Renderer.h"

#include <iostream>

Renderer::Renderer()
{
	Init();
}

Renderer::~Renderer()
{
	delete shader;
	delete VAO;
	delete VBO;
	delete EBO;
	delete tex;
}

void Renderer::Run()
{
	while (!glfwWindowShouldClose(m_Window.GetWindow()))
	{
		glClearColor(0.3984f, 0.0f, 0.2f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->Bind();
		VAO->Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		m_Window.OnUpdate();
	}
}

void Renderer::Init()
{
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW failed to initialize!" << std::endl;
		exit(-1);
	}

	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 0.5f, 1.0f
	};

	unsigned int indices[] = {
		1, 0, 2,
		0, 2, 3
	};

	shader = new Shader("vertex.shader", "fragment.shader");

	VAO = new VertexArray();
	VBO = new VertexBuffer(vertices, sizeof(vertices));
	EBO = new IndexBuffer(indices, sizeof(indices));
	tex = new Texture("assets/textures/Checkerboard.png");
	
	tex->Bind();

	VAO->SetVertexBuffer(VBO);
	VAO->SetIndexBuffer(EBO);

	VBO->SetLayout(0, 3, 20, 0);
	VBO->SetLayout(1, 2, 20, 12);
}
