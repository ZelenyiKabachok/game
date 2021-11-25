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
	glm::mat4 matPosObj1 = translate(mat4(1.0), obj1.Position);
	glm::mat4 matPosObj2 = translate(mat4(1.0), obj2.Position);

	glm::vec2 AABB1[2] = {
		glm::vec2(matPosObj1 * glm::vec4(obj1.pAABB[0], 0.0f, 1.0f)),
		glm::vec2(matPosObj1 * glm::vec4(obj1.pAABB[1], 0.0f, 1.0f)),
	};
	glm::vec2 AABB2[2] = {
		glm::vec2(matPosObj2 * glm::vec4(obj2.pAABB[0], 0.0f, 1.0f)),
		glm::vec2(matPosObj2 * glm::vec4(obj2.pAABB[1], 0.0f, 1.0f)),
	};

	if(AABB1[0].x > AABB2[0].x && AABB1[0].x < AABB2[1].x) {
		if((AABB1[0].y > AABB2[0].y && AABB1[0].y < AABB2[1].y)
		|| (AABB1[1].y > AABB2[0].y && AABB1[1].y < AABB2[1].y))
		{
			return true;
		}
	}
	if(AABB1[1].x > AABB2[0].x && AABB1[1].x < AABB2[1].x)
	{
		if((AABB1[0].y > AABB2[0].y && AABB1[0].y < AABB2[1].y)
		|| (AABB1[1].y > AABB2[0].y && AABB1[1].y < AABB2[1].y))
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

