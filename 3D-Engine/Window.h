#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(unsigned int Width = 800, unsigned int Height = 600,
		const char* Title = "OpenGL", bool Fullscreen = false);

	virtual ~Window();

	void SetVsync(bool enabled);
	void OnUpdate();
	void Destroy();

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	GLFWwindow* GetWindow();

private:
	unsigned int m_Width;
	unsigned int m_Height;
	GLFWwindow* m_Window;
};

#endif
