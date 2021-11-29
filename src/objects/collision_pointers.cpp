#include "collision_pointers.h"

void Physic::PCollisions::Delete(int index)
{
	collis.DeleteItem(index);
}

Physic::Collision* Physic::PCollisions::Add(const Shape* pShapes, int numShapes)
{
	if(!init) {	
		Collision tmp(pShapes, numShapes);
		Collision *ptr = &tmp;
		collis.Create(ptr, 1);
		init = true;
	} else { collis.NewLast(Collision(pShapes, numShapes)); }
	return &collis[collis.Size()-1];
}

Physic::Collision* Physic::PCollisions::Add(Shape** ppShapes, int numShapes)
{
	if(!init) {
		Collision tmp(ppShapes, numShapes);
		Collision *ptr = &tmp;
		collis.Create(ptr, 1);
		init = true;
    } else { collis.NewLast(Collision(ppShapes, numShapes)); }
	return &collis[collis.Size()-1];
}

Physic::Collision& Physic::PCollisions::Get(int index)
{
	return collis[index];
}

bool Physic::PCollisions::GJKcollision(const Physic::Collision& obj1
                                     , const Physic::Collision& obj2)
{
	return false;
}

bool Physic::PCollisions::AABBcollision(const Physic::Collision& obj1
                              , const Physic::Collision& obj2)
{
	glm::mat4 matPosObj1 = translate(glm::mat4(1.0), obj1.v3Position);
	glm::mat4 matPosObj2 = translate(glm::mat4(1.0), obj2.v3Position);

	glm::vec2 pV2AABB1[2] = {
		glm::vec2(matPosObj1 * glm::vec4(obj1.pV2AABB[0], 0.0f, 1.0f)),
		glm::vec2(matPosObj1 * glm::vec4(obj1.pV2AABB[1], 0.0f, 1.0f)),
	};
	glm::vec2 pV2AABB2[2] = {
		glm::vec2(matPosObj2 * glm::vec4(obj2.pV2AABB[0], 0.0f, 1.0f)),
		glm::vec2(matPosObj2 * glm::vec4(obj2.pV2AABB[1], 0.0f, 1.0f)),
	};

	if(pV2AABB1[0].x > pV2AABB2[0].x && pV2AABB1[0].x < pV2AABB2[1].x) {
		if((pV2AABB1[0].y > pV2AABB2[0].y && pV2AABB1[0].y < pV2AABB2[1].y)
		|| (pV2AABB1[1].y > pV2AABB2[0].y && pV2AABB1[1].y < pV2AABB2[1].y))
		{
			return true;
		}
	}
	if(pV2AABB1[1].x > pV2AABB2[0].x && pV2AABB1[1].x < pV2AABB2[1].x)
	{
		if((pV2AABB1[0].y > pV2AABB2[0].y && pV2AABB1[0].y < pV2AABB2[1].y)
		|| (pV2AABB1[1].y > pV2AABB2[0].y && pV2AABB1[1].y < pV2AABB2[1].y))
		{
			return true;
		}
	}
	return false;
}

void Physic::PCollisions::DetectCollision()
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

