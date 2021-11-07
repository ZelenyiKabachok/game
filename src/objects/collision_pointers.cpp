#include "collision_pointers.h"

PCollisions::PCollisions(glm::vec2 *shape, int points)
{
	Collision tmp(shape, points);
	Collision *ptr = &tmp;
	collis.Create(ptr, points);
}

void PCollisions::Delete(int index)
{
	collis.DeleteItem(index);
}

Collision& PCollisions::Add(glm::vec2 *shape, int points)
{
	collis.NewLast(Collision(shape, points));
	return collis[collis.Size()];
}

Collision& PCollisions::Get(int index)
{
	return collis[index];
}
