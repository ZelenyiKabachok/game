#include "free_camera.h"

FreeCamera::FreeCamera(const glm::vec3& v3Pos, float sp)
                  : Camera(v3Pos), speed(-sp) {}

void FreeCamera::Move(float delta_time, const bool *keys, float scroll)
{
    if(keys['W']) { this->v3Position.y -= speed * delta_time; }
    if(keys['A']) { this->v3Position.x += speed * delta_time; }
    if(keys['S']) { this->v3Position.y += speed * delta_time; }
    if(keys['D']) { this->v3Position.x -= speed * delta_time; }

    this->v3Position.z += scroll;
	this->matView = glm::translate(glm::mat4(1.0f), this->v3Position);
    this->matCamera = this->matProjection * this->matView * this->matModel;
}

