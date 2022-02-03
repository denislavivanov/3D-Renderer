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
}
