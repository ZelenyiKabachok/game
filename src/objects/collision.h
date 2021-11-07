#ifndef COLLISION_H
#define COLLISION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Класс содержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

	glm::vec2 *shape;	//Массив точек.
	glm::vec2 center;	//Центр фигуры.

	const int points;	//Количество точек.

	//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 AABB[2];

//При создании объекта CollisOb центр находится в точке (0; 0).
//Создаётся классом PCollisions.
//Форма должна быть выпуклой.
	Collision(glm::vec2 *nShape, int nPoints);

	void find_AABB_points();

public:

	void Movement(glm::mat4 matrix);

	void Rotation(glm::mat4 matrix);

	~Collision();

};

#endif
