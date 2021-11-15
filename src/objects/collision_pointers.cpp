#include "collision_pointers.h"

void PCollisions::Delete(int index)
{
	collis.DeleteItem(index);
}

unsigned int PCollisions::Add(const Shape* const shapes, int numShapes)
{
	if(!init) {	
		Collision tmp(shapes, numShapes);
		Collision *ptr = &tmp;
		collis.Create(ptr, 1);
		init = true;
	} 
	else { collis.NewLast(Collision(shapes, numShapes)); }
	return collis.Size();
}

Collision* PCollisions::Add(Shape** shapes, int numShapes)
{
	if(!init) {
		Collision tmp(shapes, numShapes);
		Collision *ptr = &tmp;
		collis.Create(ptr, 1);
		init = true;
	} 
	else { collis.NewLast(Collision(shapes, numShapes)); }
	return &collis[collis.Size()-1];
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
	if(obj1.pAABB[0].x > obj2.pAABB[0].x
	   && obj1.pAABB[0].x < obj2.pAABB[1].x)
	{
		if((obj1.pAABB[0].y > obj2.pAABB[0].y && obj1.pAABB[0].y < obj2.pAABB[1].y)
		|| (obj1.pAABB[1].y > obj2.pAABB[0].y && obj1.pAABB[1].y < obj2.pAABB[1].y))
		{
			return true;
		}
	}
	if(obj1.pAABB[1].x > obj2.pAABB[0].x
	   && obj1.pAABB[1].x < obj2.pAABB[1].x)
	{
		if((obj1.pAABB[0].y > obj2.pAABB[0].y && obj1.pAABB[0].y < obj2.pAABB[1].y)
		|| (obj1.pAABB[1].y > obj2.pAABB[0].y && obj1.pAABB[1].y < obj2.pAABB[1].y))
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

