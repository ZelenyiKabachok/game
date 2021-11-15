#ifndef COLLISION_H
#define COLLISION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shape.h"

//Класс cодержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

//Массив указателей не класс Shape.
	Shape **ppShapes;

	const unsigned int numOfShapes; 	//Размер массива.

/*
	glm::mat4 matPosition = glm::mat4(1.0f);
	glm::mat4 matRotation = glm::mat4(1.0f);
*/
	glm::vec3 Position = glm::vec3(0.0f);

//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 pAABB[2];

//Создаётся классом PCollisions.
	Collision(const Shape* const arrayOfShapes, const unsigned int num);

	Collision(Shape** arrayOfShapes, const unsigned int num);

	void find_AABB_points();

	void PrintState();

public:

	Collision(const Collision& obj);

	void Movement(glm::vec3 new_pos);

	void Rotation(float angle);

	~Collision();

};

#endif
