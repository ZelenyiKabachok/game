#ifndef COLLISION_POINTERS_H
#define COLLISION_POINTERS_H

#include "collision.h"
#include "../utility/list.h"

//Хранит все объекты типа collision.
class PCollisions {

	List<Collision> collis;

public:

	Collision& Add(glm::vec2 *shape, int points);

	Collision& Get(int index);

	void Delete(int index);

	void Init(glm::vec2 *shapes, int points);
	
	PCollisions() {}

	~PCollisions() {}	

};

#endif
