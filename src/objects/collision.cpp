#include "collision.h"

Collision::Collision(glm::vec2 *nShape, int nPoints)
							: center(glm::vec2(0.0)), points(nPoints)
{
	shape = new glm::vec2[points];
	for(int i = 0; i < points; i++) {
		shape[i] = nShape[i];
	}
	find_AABB_points();
}

void Collision::find_AABB_points()
{
	enum Faces { left, down, right, up };
	float faces[4] = { 
			shape[0].x, shape[0].y, 
			shape[0].x, shape[0].y
	};

	for(int i = 0; i < points; i++) {
		if(shape[i].x < faces[left])
		{ faces[left] = shape[i].x; }

		if(shape[i].y < faces[down])
		{ faces[down] = shape[i].y; }

		if(shape[i].x > faces[right])
		{ faces[right] = shape[i].x; }

		if(shape[i].y > faces[up])
		{ faces[up] = shape[i].y; }
	}

	AABB[0].x = faces[left];
	AABB[0].y = faces[down];

	AABB[1].x = faces[right];
	AABB[1].y = faces[up];
}

Collision::~Collision()
{
	delete[] shape;
}

void Collision::Movement(glm::mat4 matrix)
{
	center = glm::vec2(glm::vec4(center, 0.0f, 0.0f) * matrix);
	for(int i = 0; i < points; i++) {
		shape[i] = glm::vec2(glm::vec4(shape[i], 0.0f, 0.0f) * matrix);
	}
	AABB[0] = glm::vec2(glm::vec4(AABB[0], 0.0f, 0.0f) * matrix);
	AABB[1] = glm::vec2(glm::vec4(AABB[1], 0.0f, 0.0f) * matrix);
}

void Collision::Rotation(glm::mat4 matrix)
{
	for(int i = 0; i < points; i++) {
		shape[i] = glm::vec2(glm::vec4(shape[i], 0.0f, 0.0f) * matrix);
	}
	find_AABB_points();
}
