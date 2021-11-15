#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>

//Простая выпуклая геометрическая форма для
//просчёта столкновения алгоритмом gjk.
class Shape {
public:
	glm::vec2 *pPoints;				//Массив точек.
//Центр фигуры. Как правило, при создании находится в начале координат.
	glm::vec2 center;		
	const unsigned int num_points;	//Количество точек.

	Shape(glm::vec2 *pnts, glm::vec2 cntr, unsigned int num);

	Shape(const Shape& other);

	~Shape();

};

#endif
