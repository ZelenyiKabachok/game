#ifndef COLLISION_H
#define COLLISION_H

#include <cstdio>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "coll_draw.h"

//Класс cодержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

//Массив указателей на класс Shape.
	Shape **ppShapes;
	CollDraw ShRender;

	const unsigned int numOfShapes; 	//Размер массива.

	float angle;
	glm::vec3 Position = glm::vec3(0.0f);

//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 pAABB[2];
	glm::vec3 AABBSize;

//Создаётся классом PCollisions.
	Collision(const Shape* const arrayOfShapes, const unsigned int num);

	Collision(Shape** arrayOfShapes, const unsigned int num);

	void find_AABB_points();

	void find_AABB_coef();

	void PrintState();

public:

	Collision(const Collision& obj);

	void Draw(const Camera& camera);

	void Movement(glm::vec3 new_pos);

	void Rotation(float angle);

	~Collision();

};

#endif
