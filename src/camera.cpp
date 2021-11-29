#include "camera.h"

extern int Height;
extern int Width;

void Camera::Move(float delta_time)
{
	v3Position = glm::vec3(v3Position.x + ((-v3Speed.x)*delta_time),
					       v3Position.y + ((-v3Speed.y)*delta_time),
					       v3Position.z + ((-v3Speed.z)*delta_time));
	matView = glm::translate(glm::mat4(1.0f), v3Position);
    printf("Camera pos { %f; %f; %f }\n", v3Position.x, v3Position.y, v3Position.z);
}

Camera::Camera(const glm::vec3& v3Pos, const glm::vec3& v3Sp)
					: v3Position(-v3Pos), v3Speed(v3Sp)
{
    printf("Camera pos { %f; %f; %f }\n", v3Position.x, v3Position.y, v3Position.z);
	matModel = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 1.0));
	matView = glm::translate(glm::mat4(1.0f), v3Position);
	matProjection = glm::perspective(Zoom, float((float)(Width)/Height)
                                                        , 0.1f, 3000.0f);
}

void Camera::FocusOnTheObject(const Graphic::GraphObject *obj)
{
	float save = v3Position.z;
	v3Position = -obj->GetPosition();
	v3Position.z = save;
	pTarget = obj;
}

void Camera::Follow(float delta_time)
{
	ChangeSpeed(pTarget->GetSpeed());
    Move(delta_time);
}

void Camera::CancelFocus()
{
	pTarget = NULL;
}

void Camera::ChangeSpeed(const glm::vec3& v3NewSpeed)
{ v3Speed = v3NewSpeed; }

glm::mat4 Camera::GetMatrix() const
{ return matProjection * matView * matModel; }

glm::vec3 Camera::GetPosition() const { return v3Position; };
