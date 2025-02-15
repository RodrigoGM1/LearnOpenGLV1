#include "CamaraClass.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//CamaraClass::CamaraClass(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
//{
//	Position = position;
//	WordUp = up;
//	Pitch = pitch;
//	updateCameraVectors();
//}

CamaraClass::CamaraClass(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}

//CamaraClass::CamaraClass(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
//{
//	Position = glm::vec3(posX, posY, posZ);
//	WordUp = glm::vec3(upX, upY, upZ);
//	Yaw = yaw;
//	Pitch = pitch;
//	updateCameraVectors();
//}

CamaraClass::CamaraClass(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
	Position = glm::vec3(posX, posY, posZ);
	WorldUp = glm::vec3(upX, upY, upZ);
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}

//glm::mat4 CamaraClass::GetViewMatrix()
//{
//	return glm::lookAt(Position, Position + Front, Up);
//}

glm::mat4 CamaraClass::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

//void CamaraClass::ProcessKeyboard(Camara_Movement direction, float deltaTime)
//{
//	float velocity = MovementSpeed * deltaTime;
//	if (direction == FORWARD) {
//		Position += Front * velocity;
//	}
//	if (direction == BACKWARD) {
//		Position -= Front * velocity;
//	}
//	if (direction == LEFT) {
//		Position -= Rigth * velocity;
//	}
//	if (direction == RIGHT) {
//		Position += Rigth * velocity;
//	}
//}

void CamaraClass::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	float velocity = MovementSpeed * deltaTime;
	if (direction == FORWARD) {
		Position += Front * velocity;
	}
	if (direction == BACKWARD) {
		Position -= Front * velocity;
	}
	if (direction == LEFT) {
		Position -= Right * velocity;
	}
	if (direction == RIGHT) {
		Position += Right * velocity;
	}
	Position.y = 0.0f;
}

//void CamaraClass::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
//{
//	xoffset *= MouseSensitivity;
//	yoffset *= MouseSensitivity;
//
//	Yaw += xoffset;
//	Pitch += yoffset;
//
//	if (constrainPitch) {
//		if (Pitch > 89.0f) {
//			Pitch = 89.0f;
//		}
//		if (Pitch < -89.0f) {
//			Pitch = -89.0f;
//		}
//	}
//	updateCameraVectors();
//}

void CamaraClass::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	if (constrainPitch)
	{
		if (Pitch > 89.0f) {
			Pitch = 89.0f;
		}
		if (Pitch < -89.0f) {
			Pitch = -89.0f;
		}
	}

	updateCameraVectors();
}

//void CamaraClass::ProcessMouseScroll(float yoffset)
//{
//	Zoom -= (float)yoffset;
//	if (Zoom < 1.0f) {
//		Zoom = 1.0f;
//	}
//	if (Zoom > 45.0f) {
//		Zoom = 45.0f;
//	}
//}

void CamaraClass::ProcessMouseScroll(float yoffset)
{
	Zoom -= (float)yoffset;
	if (Zoom < 1.0f) {
		Zoom = 1.0f;
	}
	if (Zoom > 45.0f) {
		Zoom = 45.0f;
	}
}

//void CamaraClass::updateCameraVectors()
//{
//	glm::vec3 front;
//	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
//	front.y = sin(glm::radians(Pitch));
//	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
//	Front = glm::normalize(front);
//
//	Rigth = glm::normalize(glm::cross(Front, WordUp));
//	Up = glm::normalize(glm::cross(Rigth, Front));
//}

void CamaraClass::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}