#ifndef COLLISION_H
#define COLLISION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shape.h"

//Класс cодержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

//Массив указателей не класс Shape.
	Shape **shapes;

	const unsigned int numOfShapes; 	//Размер массива.

//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 AABB[2];

//Создаётся классом PCollisions.
	Collision(Shape *arrayOfShapes, const unsigned int num);

	void find_AABB_points();

public:

	void Movement(glm::mat4 matrix);

	void Rotation(glm::mat4 matrix);

	~Collision();

};

#endif
