#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

protected:

	glm::vec3 v3Position;

	glm::mat4 matModel;
	glm::mat4 matView;
	glm::mat4 matProjection;
    glm::mat4 matCamera;

	float Zoom = M_PI/4;

public:

    Camera(const glm::vec3& v3Pos); 

    virtual void Move(float delta_time) {}

	virtual glm::mat4 GetMatrix() const;

    virtual glm::vec3 GetPosition() const;

    ~Camera() {}

};

#endif
