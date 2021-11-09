#include "collision_pointers.h"

void PCollisions::Init(Shape *shapes, int points)
{
	Collision tmp(shapes, points);
	Collision *ptr = &tmp;
	collis.Create(ptr, points);
}

void PCollisions::Delete(int index)
{
	collis.DeleteItem(index);
}

Collision& PCollisions::Add(Shape *shapes, int points)
{
	collis.NewLast(Collision(shapes, points));
	return collis[collis.Size()];
}

Collision& PCollisions::Get(int index)
{
	return collis[index];
}

bool PCollisions::GJKcollision(const Collision& obj1, const Collision& obj2)
{
	return false;
}

bool PCollisions::AABBcollision(const Collision& obj1, const Collision& obj2)
{
	if(obj1.AABB[0].x > obj2.AABB[0].x
	   && obj1.AABB[0].x < obj2.AABB[1].x)
	{
		if((obj1.AABB[0].y > obj2.AABB[0].y && obj1.AABB[0].y < obj2.AABB[1].y)
		|| (obj1.AABB[1].y > obj2.AABB[0].y && obj1.AABB[1].y < obj2.AABB[1].y))
		{
			return true;
		}
	}
	if(obj1.AABB[1].x > obj2.AABB[0].x
	   && obj1.AABB[1].x < obj2.AABB[1].x)
	{
		if((obj1.AABB[0].y > obj2.AABB[0].y && obj1.AABB[0].y < obj2.AABB[1].y)
		|| (obj1.AABB[1].y > obj2.AABB[0].y && obj1.AABB[1].y < obj2.AABB[1].y))
		{
			return true;
		}
	}
	return false;
}

void PCollisions::DetectCollision()
{
	for(int i = 0; i < collis.Size(); i++) {
		for(int j = 0; j < collis.Size() - i; j++) {
			if(AABBcollision(collis[i], collis[j])) {
//				GJKcollision(collis[i], collis[j]);
				printf("Have collision\n");
			}
		}
	}
}

