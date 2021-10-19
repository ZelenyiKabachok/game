#ifndef GRAVITY_OBJECT_H
#define GRAVITY_OBJECT_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "sprite.h"

class GravityObject : public GraphObject {

	float mass;
	float cooficient;

public:
	
	GravityObject(const Shader& sh, const Texture2D& tex, const vec3& pos,
						const vec3& size, const vec3& speed, float m, float coof) 
		: GraphObject(sh, tex, pos, size, speed), 
		mass(m), cooficient(coof) {}

	void Attract(float delta_time);

};

#endif
