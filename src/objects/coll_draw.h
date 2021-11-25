#ifndef COLL_DRAW_H
#define COLL_DRAW_H

#include "shape_draw.h"

extern ResourceManager resources;

class CollDraw {

	ShapeDraw **ppGraphic;
	unsigned int number;

public:
	
	CollDraw() {}

	void Init(Shape **ppShape, unsigned int numOfShapes, const glm::vec2 *pAABB);

	void Draw(const Camera& camera, const glm::vec3& pos, float angle);

	~CollDraw();

};

#endif
