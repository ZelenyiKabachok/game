#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "objects/graphic_object.h"

namespace Graphic {
class GraphObject;
}

class Camera {
	
	glm::vec3 v3Position;
	glm::vec3 v3Speed;

	glm::mat4 matModel;
	glm::mat4 matView;
	glm::mat4 matProjection;

	const Graphic::GraphObject *pTarget = NULL; //в '~Camera' не уничтожается.

	const float Zoom = M_PI/4;

public:

//Начинает следовать за указанным объектом.
//Нужно быть очень аккуратным.
	void FocusOnTheObject(const Graphic::GraphObject *obj);

//Вызывается если нужно отменить фокус,
//или перед уничтожением объекта, за которым следует камера.
	void CancelFocus();

	void Move(float delta_time);

	Camera(const glm::vec3& v3Pos = glm::vec3(0)
         , const glm::vec3& v3Sp = glm::vec3(0));
	
	glm::mat4 GetMatrix() const;

    void Follow(float delta_time);

	void ChangeSpeed(const glm::vec3& v3NewSpeed);

	glm::vec3 GetPosition() const;

};

#endif
