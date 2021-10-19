#ifndef GRAVITY_OBJECT_H
#define GRAVITY_OBJECT_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class GravityObject {

	float mass;

public:
	
	GravityObject(float m) : mass(m) {}

	vec3 Attract(vec3& position, float delta_time);

};

#endif
