#ifndef COLLISION_POINTERS_H
#define COLLISION_POINTERS_H

#include <cstdio>
#include "collision.h"
#include "../utility/list.h"

//Хранит все объекты типа collision.
class PCollisions {

	List<Collision> collis;

//Обноруживает столкновения алгоритмом gjk
//Вызывается для двух объектов, у которых обнаружилось столкновение
//алгоритмом AABB.
	bool GJKcollision(const Collision& obj1, const Collision& obj2); 

	bool AABBcollision(const Collision& obj1, const Collision& obj2);

public:

	Collision& Add(Shape *shapes, int points);

	Collision& Get(int index);

	void Delete(int index);

	void Init(Shape *shapes, int points);

//Обнаруживает столкновения.
	void DetectCollision();
	
	PCollisions() {}

	~PCollisions() {}	

};

#endif
