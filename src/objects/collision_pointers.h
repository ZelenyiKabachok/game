#ifndef COLLISION_POINTERS_H
#define COLLISION_POINTERS_H

#include <cstdio>
#include "collision.h"
#include "../utility/list.h"

//Хранит все объекты типа collision.
class PCollisions {

	List<Collision> collis;
	bool init = false;

//Обноруживает столкновения алгоритмом gjk
//Вызывается для двух объектов, у которых обнаружилось столкновение
//алгоритмом AABB.
	bool GJKcollision(const Collision& obj1, const Collision& obj2); 

	bool AABBcollision(const Collision& obj1, const Collision& obj2);

public:

	unsigned int Add(const Shape* const shapes, int numShapes);

//принимает массив указателей на Shape.
	Collision* Add(Shape** shapes, int numShapes);

	Collision& Get(int index);

	void PrintState();

	void Delete(int index);

//Обнаруживает столкновения.
	void DetectCollision();
	
	PCollisions() {}

	~PCollisions() {}	

};

#endif
