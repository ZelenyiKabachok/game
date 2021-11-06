#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "objects/graphic_object.h"

using glm::vec3;
using glm::mat4;

class GraphObject;

class Camera {
	
	vec3 cameraPos;
	vec3 cameraSpeed;

	mat4 Model;
	mat4 View;
	mat4 Projection;

	const GraphObject *target = NULL; //в ~Camera не уничтожается.
	bool focus = false;

	const float cameraZoom = M_PI/4;

public:

//Начинает следовать за указанным объектом.
//Нужно быть очень аккуратным.
	void FocusOnTheObject(const GraphObject *obj);

//Вызывается если нужно отменить фокус,
//или перед уничтожением объекта, за которым следует камера.
	void CancelFocus();

	mat4 MoveCamera(float delta_time);

	Camera(const vec3& Position = vec3(0), const vec3& Speed = vec3(0));
	
	mat4 GetCameraMatrix() const;

	void ChangeCameraSpeed(const vec3& NewSpeed);

	vec3 GetPosition() const;

};

#endif
