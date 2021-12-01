#ifndef COLLISION_POINTERS_H
#define COLLISION_POINTERS_H

#include <cstdio>
#include "../utility/collision_in_files.h"
#include "../utility/list.h"

namespace Physic {

//Хранит все объекты типа collision.
class PCollisions {

	List<Collision> collis;

//Вызывается для двух объектов, у которых обнаружилось столкновение
//алгоритмом AABB.
	bool GJKcollision(const Collision& obj1, const Collision& obj2); 

//Обнаруживает столкновения алгоритмом AABB
	bool AABBcollision(const Collision& obj1, const Collision& obj2);

public:

	Collision* Add(const Shape* pShapes, int numShapes);

//принимает массив указателей на Shape.
	Collision* Add(Shape** ppShapes, int numShapes);

    Collision* Add(const char *sCollis);

    Collision* Add(Collision& collision);

	Collision& Get(int index);

	void PrintState();

	void Delete(int index);

//Обнаруживает столкновения.
	void DetectCollision();
	
	PCollisions() {}

	~PCollisions() {}	

};
}

#endif
