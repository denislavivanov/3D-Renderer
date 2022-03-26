#include "Renderer.h"

#include <iostream>

static float deltaTime = 0.0f;
static float lastFrame = 0.0f;
static bool  MouseInit = true;

Camera	  Renderer::m_Camera;
glm::vec2 Renderer::m_LastMousePosition;

Renderer::Renderer()
	: m_Window(1280, 1024),
	  m_Shader("Shaders/vertex.shader", "Shaders/fragment.shader"),
	  m_Model("assets/head/"),
	  m_AntiAliasing(true)
{
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(m_Window.GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_Window.GetWindow(), MouseInput);
	glfwSetScrollCallback(m_Window.GetWindow(), ScrollInput);

	m_ViewLocation		 = glGetUniformLocation(m_Shader.GetID(), "view");
	m_ProjectionLocation = glGetUniformLocation(m_Shader.GetID(), "projection");
}

Renderer::Renderer(const std::string& scenePath)
	: m_Window(1280, 1024),
	  m_Shader("Shaders/vertex.shader", "Shaders/fragment.shader"),
	  m_Model(scenePath),
	  m_AntiAliasing(true)
{
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(m_Window.GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_Window.GetWindow(), MouseInput);
	glfwSetScrollCallback(m_Window.GetWindow(), ScrollInput);

	m_ViewLocation = glGetUniformLocation(m_Shader.GetID(), "view");
	m_ProjectionLocation = glGetUniformLocation(m_Shader.GetID(), "projection");
}

Renderer::~Renderer()
{
}

void Renderer::Run()
{
	while (!glfwWindowShouldClose(m_Window.GetWindow()))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		KeyboardInput(m_Window.GetWindow());

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_ViewMatrix = glm::lookAt(m_Camera.GetPosition(), m_Camera.GetPosition() + m_Camera.GetFrontDirection(),
							m_Camera.GetUpDirection());

		m_ProjectionMatrix = glm::perspective(glm::radians(m_Camera.GetFOV()), (float)m_Window.GetWidth() / m_Window.GetHeight(),
												0.1f, 100.0f);

		glUniformMatrix4fv(m_ViewLocation, 1, GL_FALSE, glm::value_ptr(m_ViewMatrix));
		glUniformMatrix4fv(m_ProjectionLocation, 1, GL_FALSE, glm::value_ptr(m_ProjectionMatrix));

		m_Model.Draw(m_Shader);

		m_Window.OnUpdate();
	}
}

void Renderer::SetAntiAliasing(bool enabled)
{
	if (enabled)
	{
		glEnable(GL_MULTISAMPLE);
	}
	else
	{
		glDisable(GL_MULTISAMPLE);
	}
}

void Renderer::KeyboardInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		m_AntiAliasing = !m_AntiAliasing;
		SetAntiAliasing(m_AntiAliasing);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_Camera.Move(FORWARD, deltaTime);
	}
	
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_Camera.Move(BACKWARD, deltaTime);
	}
	
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_Camera.Move(LEFT, deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_Camera.Move(RIGHT, deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		m_Camera.Move(UP, deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		m_Camera.Move(DOWN, deltaTime);
	}
}


void Renderer::MouseInput(GLFWwindow* window, double x, double y)
{
	if (MouseInit)
	{
		m_LastMousePosition.x = x;
		m_LastMousePosition.y = y;

		MouseInit = false;
	}

	float deltaX = x - m_LastMousePosition.x;
	float deltaY = m_LastMousePosition.y - y;
	
	m_LastMousePosition.x = x;
	m_LastMousePosition.y = y;

	m_Camera.Rotate(deltaX, deltaY);
}

void Renderer::ScrollInput(GLFWwindow* window, double x, double y)
{
	m_Camera.Zoom(y);
}
