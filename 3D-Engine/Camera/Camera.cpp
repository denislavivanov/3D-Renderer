#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, 
				float pitch, float sensitivity, float fov, float speed)
{
	m_Up = up;
	m_Yaw = yaw;
	m_Pitch = pitch;
	m_Position = position;

	m_FOV = fov;
	m_MovementSpeed = speed;
	m_MouseSensitivity = sensitivity;
	
	CalculateAxes();
}

void Camera::CalculateAxes()
{
	m_Front.x = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front.y = sin(glm::radians(m_Pitch));
	m_Front.z = -(cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch)));
	m_Front = glm::normalize(m_Front);

	m_Right = glm::normalize(glm::cross(m_Front, m_Up));
}

void Camera::Move(Direction direction, float deltaTime)
{
	float distance = m_MovementSpeed * deltaTime;

	switch (direction)
	{
		case FORWARD:
		{
			m_Position += distance * m_Front;
		}break;
		case BACKWARD:
		{
			m_Position -= distance * m_Front;
		}break;
		case LEFT:
		{
			m_Position -= distance * m_Right;
		}break;
		case RIGHT:
		{
			m_Position += distance * m_Right;
		}break;
		case UP:
		{
			m_Position += distance * m_Up;
		}break;
		case DOWN:
		{
			m_Position -= distance * m_Up;
		}break;
	}
}

void Camera::Rotate(double deltaYaw, double deltaPitch)
{
	deltaYaw *= m_MouseSensitivity;
	deltaPitch *= m_MouseSensitivity;

	m_Yaw += deltaYaw;
	m_Pitch += deltaPitch;

	if (m_Pitch > 89.0f)
	{
		m_Pitch = 89.0f;
	}
	
	if (m_Pitch < -89.0f)
	{
		m_Pitch = -89.0f;
	}

	CalculateAxes();
}

void Camera::Zoom(double deltaFOV)
{
	m_FOV -= deltaFOV;

	if (m_FOV < 1.0f)
	{
		m_FOV = 1.0f;
	}
	
	if (m_FOV > 45.0f)
	{
		m_FOV = 45.0f;
	}
}

float Camera::GetFOV()
{
	return m_FOV;
}

const glm::vec3& Camera::GetPosition()
{
	return m_Position;
}

const glm::vec3& Camera::GetUpDirection()
{
	return m_Up;
}

const glm::vec3& Camera::GetFrontDirection()
{
	return m_Front;
}
