#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>

namespace Physic {

//Простая выпуклая геометрическая форма для
//просчёта столкновения.
struct Shape {
	glm::vec2 *pV2Points;			//Массив точек.
//Центр фигуры. Как правило, при создании находится в начале координат.
	glm::vec2 v2Center;		
	const unsigned int num_points;	//Количество точек.

	Shape(glm::vec2 *pV2Pnts, glm::vec2 v2Cntr, unsigned int num);

	Shape(const Shape& other);

	~Shape();

};
}

#endif
