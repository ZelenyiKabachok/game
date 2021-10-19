#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;

class Camera {
	
	vec3 cameraPos;
	vec3 cameraSpeed;

	mat4 Model;
	mat4 View;
	mat4 Projection;

	const float cameraZoom = M_PI/4;

public:

	Camera(const vec3& Position, const vec3& Speed);

	mat4 MoveCamera(float delta_time);

	vec3 GetPosition() { return cameraPos; };
	
	mat4 GetCameraMatrix();

	void ChangeCameraSpeed(const vec3& NewSpeed);

};

#endif
