#pragma once

#include <GLFW/glfw3.h>
#include "Event.h"

class Window
{
public:
	Window(unsigned int Width = 800, unsigned int Height = 600,
		const char* Title = "OpenGL", bool Fullscreen = false);

	void SetVsync(bool enabled);

	void OnUpdate();

	void Destroy();

	unsigned int GetWidth() const;

	unsigned int GetHeight() const;

	GLFWwindow* GetWindow();

	virtual ~Window();

private:
	void SetEvents();

private:
	unsigned int m_Width;
	unsigned int m_Height;
	GLFWwindow* m_Window;
};

