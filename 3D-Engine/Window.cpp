#include "Window.h"
#include <iostream>


Window::Window(unsigned int Width, unsigned int Height, 
	const char* Title, bool Fullscreen)
{
	if (!glfwInit())
	{
		std::cerr << "GLFW failed to initialize!" << std::endl;
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(Width, Height, Title, Fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

	if (!m_Window)
	{
		std::cerr << "Window Creation failed! Closing..." << std::endl;
		exit(-1);
	}
	else
	{
		m_Width = Width;
		m_Height = Height;
	}

	glfwMakeContextCurrent(m_Window);
	
	SetVsync(true);
}

void Window::SetVsync(bool enabled)
{
	glfwSwapInterval(enabled ? 1 : 0);
}

GLFWwindow* Window::GetWindow()
{
	return m_Window;
}

void Window::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void Window::Destroy()
{
	glfwDestroyWindow(m_Window);
}

unsigned int Window::GetWidth() const
{
	return m_Width;
}

unsigned int Window::GetHeight() const
{
	return m_Height;
}

Window::~Window()
{
	Window::Destroy();
}

void Window::SetEvents()
{
	
}
