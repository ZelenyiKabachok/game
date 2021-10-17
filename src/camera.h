#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;

class Camera {
	
	vec3 cameraPos;

	mat4 Model;
	mat4 View;
	mat4 Projection;

	float RightSpeed;
	float UpSpeed;
	float DistanceSpeed;

	const float cameraZoom = M_PI/4;

public:

	Camera(vec3 Position, float NewSpeedX, float NewSpeedY, float NewSpeedZ);

	mat4 MoveCamera(float delta_time);

	vec3 GetPosition() { return cameraPos; };

	mat4 GetModelMatrix() { return Model; };

	mat4 GetViewMatrix() { return View; };

	mat4 GetProjectionMatrix() { return Projection; };

	void ChangeCameraSpeed(float NewSpeedX, float NewSpeedY, float NewSpeedZ)
	{ RightSpeed = NewSpeedX; UpSpeed = NewSpeedY; DistanceSpeed = NewSpeedZ; }

};

#endif
