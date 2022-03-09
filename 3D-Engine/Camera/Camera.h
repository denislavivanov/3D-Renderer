#pragma once

#include <iostream>
#include <glm/glm.hpp>

enum Direction
{
	FORWARD,
	BACKWARD,
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class Camera
{
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 2.5f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = 0.0f, float pitch = 0.0f, float sensitivity = 0.07f,
		float fov = 45.0f, float speed = 1.5f);

	void Move(Direction direction, float deltaTime);
	void Rotate(double deltaYaw, double deltaPitch);
	void Zoom(double deltaFOV);

	float GetFOV();

	const glm::vec3& GetPosition();
	const glm::vec3& GetUpDirection();
	const glm::vec3& GetFrontDirection();

private:
	void CalculateAxes();

private:
	float m_Yaw;
	float m_Pitch;
	float m_MovementSpeed;
	float m_MouseSensitivity;
	float m_FOV;

	glm::vec3 m_Position;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
};

