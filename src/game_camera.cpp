#include "game_camera.h"

void GameCamera::Move(float delta_time)
{
    this->v3Position += v3Speed * delta_time;
	this->matView = glm::translate(glm::mat4(1.0f), this->v3Position);
    this->matCamera = this->matProjection * this->matView * this->matModel;
}

GameCamera::GameCamera(const glm::vec3& v3Pos, const glm::vec3& v3Sp)
					: Camera(v3Pos), v3Speed(-v3Sp) {}

void GameCamera::FocusOnTheObject(const Graphic::GraphObject *obj)
{
	float save = this->v3Position.z;
	this->v3Position = -obj->GetPosition();
	this->v3Position.z = save;
	pTarget = obj;
}

void GameCamera::Follow(float delta_time)
{
	ChangeSpeed(pTarget->GetSpeed());
    Move(delta_time);
}

void GameCamera::CancelFocus()
{
	pTarget = NULL;
}

void GameCamera::ChangeSpeed(const glm::vec3& v3NewSpeed)
{ v3Speed = -v3NewSpeed; }
