#include "shape.h"

Shape::Shape(glm::vec2 *pnts, glm::vec2 cntr, unsigned int quant)
			: center(cntr), num_points(quant)
{
	pPoints = new glm::vec2[num_points];
	for(unsigned int i = 0; i < num_points; i++) {
		pPoints[i] = pnts[i];
	}
}

Shape::Shape(const Shape& other)
			: center(other.center), num_points(other.num_points)
{
	pPoints = new glm::vec2[num_points];
	for(unsigned int i = 0; i < num_points; i++) {
		pPoints[i] = other.pPoints[i];
	}
}

Shape::~Shape()
{
	delete[] pPoints;
}
