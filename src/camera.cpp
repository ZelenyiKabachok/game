#include "camera.h"
#include <cstdio>

extern int Height;
extern int Width;

Camera::Camera(vec3 Position, float NewSpeedX, float NewSpeedY, float NewSpeedZ) :
							cameraPos((-Position)), RightSpeed(NewSpeedX), 
							UpSpeed(NewSpeedY), DistanceSpeed(NewSpeedZ)
{
	Model = glm::rotate(mat4(1.0f), 0.0f, vec3(0.0, 0.0, 1.0));
	View = glm::translate(mat4(1.0f), cameraPos);
	Projection = glm::perspective(cameraZoom, float((float)(Width)/Height), 0.1f, 100.0f);
}

mat4 Camera::MoveCamera(float delta_time)
{

	cameraPos = vec3(cameraPos.x + ((-RightSpeed)*delta_time),
					 cameraPos.y + ((-UpSpeed)*delta_time),
					 cameraPos.z + ((-DistanceSpeed)*delta_time));

	View = glm::translate(mat4(1.0f), cameraPos);
	return Projection * View * Model;
}
