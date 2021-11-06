#include "camera.h"

extern int Height;
extern int Width;

mat4 Camera::MoveCamera(float delta_time)
{
	if(focus) { 
		ChangeCameraSpeed(target->GetSpeed());
	}
	cameraPos = vec3(cameraPos.x + ((-cameraSpeed.x)*delta_time),
					 cameraPos.y + ((-cameraSpeed.y)*delta_time),
					 cameraPos.z + ((-cameraSpeed.z)*delta_time));

	View = glm::translate(mat4(1.0f), cameraPos);
	return Projection * View * Model;
}

Camera::Camera(const vec3& Position, const vec3& Speed) :
					cameraPos((-Position)), cameraSpeed(Speed)
{
	Model = glm::rotate(mat4(1.0f), 0.0f, vec3(0.0, 0.0, 1.0));
	View = glm::translate(mat4(1.0f), cameraPos);
	Projection = glm::perspective(cameraZoom, float((float)(Width)/Height), 0.1f, 3000.0f);
}

void Camera::FocusOnTheObject(const GraphObject *obj)
{
	float save = cameraPos.z;
	cameraPos = -obj->GetPosition();
	cameraPos.z = save;

	target = obj;
	focus = true;
}

void Camera::CancelFocus()
{
	target = NULL;
	focus = false;
}

void Camera::ChangeCameraSpeed(const vec3& newSpeed)
{ cameraSpeed = newSpeed; }

mat4 Camera::GetCameraMatrix() const
{ return Projection * View * Model; }

vec3 Camera::GetPosition() const { return cameraPos; };
