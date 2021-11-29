#ifndef COLLISION_H
#define COLLISION_H

#include <cstdio>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "coll_draw.h"

namespace Physic {

class PCollisions;

//Класс cодержит форму, для которой расчитываются столкновения.
class Collision {
	friend class PCollisions;

//Массив указателей на класс Shape.
	Shape **ppShapes;
	Graphic::CollDraw ShRender;

	const unsigned int numOfShapes; 	//Размер массива.

	float angle;
	glm::vec3 v3Position = glm::vec3(0.0f);

//Хранит нижнюю левую и верхнюю правую точки прямоугольника.
	glm::vec2 pV2AABB[2];

//Создаётся классом PCollisions.
	Collision(const Shape* arrayOfShapes, const unsigned int num);

	Collision(Shape** arrayOfShapes, const unsigned int num);

	void find_AABB_points();

	void PrintState();

public:

	Collision(const Collision& obj);

	void Draw(const Camera& camera);

    void BeginDraw(Graphic::Shader coll, Graphic::Shader aabb
                    , Graphic::Texture2D collTex);

	void Movement(glm::vec3 v3NewPos);

	void Rotation(float angle);

	~Collision();

};
}

#endif
