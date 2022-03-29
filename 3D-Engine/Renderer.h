#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "Camera/Camera.h"


class Renderer
{
public:
	Renderer();
	Renderer(const std::string& scenePath);

	~Renderer();

	void Run();


protected:
	void KeyboardInput(GLFWwindow* window);
	void SetAntiAliasing(bool enabled);

	static void ToggleAntiAliasing();
	static void MouseInput(GLFWwindow* window, double x, double y);
	static void ScrollInput(GLFWwindow* window, double x, double y);
	static void MSAAInput(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	Window m_Window;
	Shader m_Shader;
	Model m_Model;
	
	static Camera m_Camera;
	static glm::vec2 m_LastMousePosition;
	static bool m_AntiAliasing;

	int m_ViewLocation;
	int m_ProjectionLocation;

	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
};

