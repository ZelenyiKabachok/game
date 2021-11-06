#include "collision.h"

CollisionOb::CollisionOb(glm::vec2 *nShape, int nPoints)
							: center(glm::vec2(0.0)), points(nPoints)
{
	shape = new glm::vec2[points];
	for(int i = 0; i < points; i++) {
		shape[i] = nShape[i];
	}
}

CollisionOb::~CollisionOb()
{
	delete[] shape;
}

void CollisionOb::Change(glm::mat4 matrix)
{
	center = glm::vec2(glm::vec4(center, 0.0f, 0.0f) * matrix);
	for(int i = 0; i < points; i++) {
		shape[i] = glm::vec2(glm::vec4(shape[i], 0.0f, 0.0f) * matrix);
	}
}
