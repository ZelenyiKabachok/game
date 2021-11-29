#include "shape.h"

Physic::Shape::Shape(glm::vec2 *pV2Pnts, glm::vec2 v2Cntr, unsigned int quant)
			        : v2Center(v2Cntr), num_points(quant)
{
	pV2Points = new glm::vec2[num_points];
	for(unsigned int i = 0; i < num_points; i++) {
		pV2Points[i] = pV2Pnts[i];
	}
}

Physic::Shape::Shape(const Shape& other)
			  : v2Center(other.v2Center), num_points(other.num_points)
{
	pV2Points = new glm::vec2[num_points];
	for(unsigned int i = 0; i < num_points; i++) {
		pV2Points[i] = other.pV2Points[i];
	}
}

Physic::Shape::~Shape()
{
	delete[] pV2Points;
}
