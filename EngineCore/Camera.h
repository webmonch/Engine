#pragma once
#include "glm.hpp"
#include <gtx/transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();

public:
	const glm::vec3 & GetPosition() const	{ return _position; }
	void SetPosition(glm::vec3 position)	{ _position = position; }
	void LookAt(glm::vec3 lookAtPos)		{ _lookAt	= lookAtPos; }

	//TODO(vlad): cache matrix
	glm::mat4 ViewMatrix() const { return glm::lookAt(glm::vec3(-5, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); }
	glm::mat4 ProjectionMatrix() const { return glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f); }

private:
	void RecalculateData(); //NOTE(vlad): recalcluate cached data when one of parameters change

private:
	glm::vec3 _position;
	glm::vec3 _lookAt;

	float _fieldOfViewDegrees = 45;
	float _screenRatio = 4.0f / 3.0f;//TODO(vlad): claculate based on set in preferences prefered resolution
	float _nearPlane = 0.1f;
	float _farPlane = 100.0f;
};

