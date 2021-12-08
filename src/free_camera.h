#ifndef FREE_CAMERA_H
#define FREE_CAMERA_H

#include "camera.h"

class Camera;

class FreeCamera : public Camera {

	float speed;

public:

    FreeCamera(const glm::vec3& v3Pos = glm::vec3(0), float sp = 8);

    virtual void Move(float delta_time, const bool *keys, float scroll);

    virtual ~FreeCamera() {}
	
};

#endif
