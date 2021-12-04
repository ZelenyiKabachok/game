#include "camera.h"

extern int Height;
extern int Width;

Camera::Camera(const glm::vec3& v3Pos)
					: v3Position(-v3Pos)
{
	matModel = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 1.0));
	matView = glm::translate(glm::mat4(1.0f), v3Position);
	matProjection = glm::perspective(Zoom, float((float)(Width)/Height)
                                                        , 0.1f, 3000.0f);
    matCamera = matProjection * matView * matModel;
}

glm::mat4 Camera::GetMatrix() const
{ return matCamera; }

glm::vec3 Camera::GetPosition() const { return v3Position; }
